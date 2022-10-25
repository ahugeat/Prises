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
  , m_position(gf::vec(3, 5) * GameData::TileSize)
  , m_direction(0.0f)
  , m_body(physics.createPlayerBody(m_position, 0.0f)) {

  }

  void PlayerEntity::update(gf::Time time) {
    // Compute the next position
    gf::Vector2f nextPosition = m_position + m_direction * PlayerVelocity * time.asSeconds();

    // Update physics
    b2Vec2 vel = m_physicsEngine.computeGameToPhysicsCoordinates(nextPosition);
    m_body->SetTransform(vel, 0.0f);

    // Move the player
    m_position = nextPosition;

    // Reset direction
    m_direction = gf::vec(0.0f, 0.0f);
  }

  void PlayerEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    gf::RectangleShape player;
    player.setSize(GameData::PlayerSize);
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
