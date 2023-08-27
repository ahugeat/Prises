#include "PlayerEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/VectorOps.h>

#include "GameHub.h"
#include "PhysicsState.h"

namespace {
  constexpr float PlayerVelocity = 500.0f;
}

namespace pr {
  PlayerEntity::PlayerEntity(PhysicsState& physics)
  : m_physicsEngine(physics.engine)
  , m_direction(0.0f)
  , m_body(physics.createPlayerBody(gf::vec(3, 5) * GameData::TileSize)) {

  }

  void PlayerEntity::update([[maybe_unused]] gf::Time time) {
    // Update physics
    const gf::Vector2f impulse = m_direction * PlayerVelocity;
    m_body->SetLinearVelocity(m_physicsEngine.computeGameToPhysicsCoordinates(impulse));

    // Reset direction
    m_direction = gf::vec(0.0f, 0.0f);
  }

  void PlayerEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    const gf::Vector2f currentPosition = m_physicsEngine.computePhysicsToGameCoordinates(m_body->GetPosition());

    gf::RectangleShape player;
    player.setSize(GameData::PlayerSize);
    player.setColor(gf::Color::Blue);
    player.setAnchor(gf::Anchor::Center);
    player.setPosition(currentPosition);
    target.draw(player, states);
  }

  void PlayerEntity::move(gf::Direction direction) {
    m_direction += gf::displacement(direction);
    assert(m_direction.x <= 1.0f && m_direction.x >= -1.0f);
    assert(m_direction.y <= 1.0f && m_direction.y >= -1.0f);
  }
}
