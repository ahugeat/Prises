#include "MapEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/SpriteBatch.h>

#include "GameModel.h"

namespace flo {
  MapEntity::MapEntity(GameModel& model)
  : m_model(model) {

  }

  void MapEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    const LevelModel& levelModel = m_model.levels[m_model.currentLevel];
    for (int row = 0; row < levelModel.size.row; ++row) {
      for (int col = 0; col < levelModel.size.col; ++col) {
        // Draw wall
        if (levelModel.tiles[row][col] == TileType::Wall) {
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
