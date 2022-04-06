#include "MapEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/SpriteBatch.h>

#include "GameModel.h"

namespace pr {
  MapEntity::MapEntity(GameModel& model)
  : m_model(model) {

  }

  void MapEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    const LevelModel& levelModel = m_model.getCurrentLevel();
    for (int row = 0; row < levelModel.size.row; ++row) {
      for (int col = 0; col < levelModel.size.col; ++col) {
        // Draw wall
        if (levelModel.tileAt(col, row) == TileType::Wall) {
          gf::RectangleShape rect;
          rect.setSize(GameModel::TileSize);
          rect.setColor(gf::Color::Red);
          rect.setPosition(gf::vec(col, row) * GameModel::TileSize);
          target.draw(rect, states);
        }
      }
    }
  }
}
