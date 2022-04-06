#include "PlayerEntity.h"

#include <gf/Collision.h>
#include <gf/Log.h>
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/VectorOps.h>

#include "GameModel.h"

namespace {
  constexpr float PlayerVelocity = 500.0f;
}

namespace pr {
  PlayerEntity::PlayerEntity(GameModel& model)
  : m_model(model)
  , m_position(model.getCurrentLevel().size * GameModel::TileSize / 2)
  , m_direction(0.0f) {

  }

  void PlayerEntity::update(gf::Time time) {
    // Compute the next position
    gf::Vector2f nextPosition = m_position + m_direction * PlayerVelocity * time.asSeconds();

    const LevelModel& currentLevel = m_model.getCurrentLevel();

    // Check collision with all tiles
    // TODO: inefficient, just checks tiles around
    for (int row = 0; row < currentLevel.size.row; ++row) {
      for (int col = 0; col < currentLevel.size.col; ++col) {
        // Get the player hitbox
        gf::RectF playerHitbox = gf::RectF::fromCenterSize(nextPosition, GameModel::PlayerSize);

        // Get the wall hitbox
        gf::RectF tileHitbox = gf::RectF::fromPositionSize(gf::vec(col, row) * GameModel::TileSize, GameModel::TileSize);
        TileType tile = currentLevel.tileAt(col, row);

        gf::Penetration p;
        if (tile == TileType::Wall && gf::collides(tileHitbox, playerHitbox, p)) {
          // Clamp the player position
          nextPosition += p.normal * p.depth;
        }
      }
    }

    // Move the player
    m_position = nextPosition;

    // Reset direction
    m_direction = gf::vec(0.0f, 0.0f);
  }

  void PlayerEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    gf::RectangleShape player;
    player.setSize(GameModel::PlayerSize);
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
