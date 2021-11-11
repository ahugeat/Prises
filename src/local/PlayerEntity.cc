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
  PlayerEntity::PlayerEntity(GameModel& model)
  : m_position(model.levels[model.currentLevel].size * GameModel::TileSize / 2)
  , m_direction(0.0f) {

  }

  void PlayerEntity::update(gf::Time time) {
    // Move the player
    m_position += m_direction * PlayerVelocity * time.asSeconds();

    // Reset direction
    m_direction = gf::vec(0.0f, 0.0f);
  }

  void PlayerEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    gf::CircleShape player;
    player.setRadius(GameModel::TileSize.width / 2);
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
