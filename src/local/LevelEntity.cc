#include "LevelEntity.h"

#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/SpriteBatch.h>

#include "GameData.h"

namespace pr {
  LevelEntity::LevelEntity(GameData& model)
  : m_model(model) {

  }

  void LevelEntity::render(gf::RenderTarget& target, const gf::RenderStates& states) {
    LevelData& levelData = m_model.getCurrentLevel();

    for (auto& layer : levelData.layers) {
      target.draw(layer, states);
    }
  }
}
