#ifndef LOCAL_GAME_MODEL_H_
#define LOCAL_GAME_MODEL_H_

#include <vector>

#include <gf/ResourceManager.h>
#include <gf/Span.h>
#include <gf/Tmx.h>
#include <gf/Vector.h>

#include "LevelData.h"

namespace pr {
  struct GameModel {
    static constexpr gf::Vector2i TileSize = gf::vec(128, 128);
    static constexpr gf::Vector2i WorldSize = gf::vec(1024, 1024) * TileSize;
    static constexpr gf::Vector2i PlayerSize = TileSize / 2;

    GameModel(gf::ResourceManager& ressources);

    LevelData& getCurrentLevel();

    int currentLevel = 0;
    std::vector<LevelData> levels;
  };
}

#endif // LOCAL_GAME_MODEL_H_
