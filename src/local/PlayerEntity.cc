#include "PlayerEntity.h"

#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/VectorOps.h>

#include "GameModel.h"

namespace {
  constexpr gf::Vector2f PlayerVelocity = gf::vec(1000.0f, 1000.0f);
}

namespace flo {
  PlayerEntity::PlayerEntity()
  : m_position(GameModel::WorldSize / 2) {

  }

  void PlayerEntity::update(gf::Time time) {
    gf::Log::debug("Direction: %f;%f\n", m_direction.x, m_direction.y);

    // Move the player
    m_position += m_direction * PlayerVelocity * time.asSeconds();

    // Reset direction
    m_direction = gf::vec(0.0f, 0.0f);
  }

  void PlayerEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    gf::CircleShape player;
    player.setRadius(60.0f);
    player.setColor(gf::Color::Blue);
    player.setAnchor(gf::Anchor::Center);
    player.setPosition(m_position);
    target.draw(player, states);
  }

  void PlayerEntity::move(gf::Direction direction) {
    m_direction += gf::displacement(direction);
    assert(m_direction.x <= 1.0f && m_direction.x >= -1.0f);
    assert(m_direction.y <= 1.0f && m_direction.y >= -1.0f);
  }
}
