#ifndef LOCAL_GAME_DATA_H_
#define LOCAL_GAME_DATA_H_

#include <vector>

#include <gf/ResourceManager.h>
#include <gf/Span.h>
#include <gf/Tmx.h>
#include <gf/Vector.h>

#include "LevelData.h"

namespace pr {
  struct GameData {
    static constexpr gf::Vector2i TileSize = gf::vec(256, 128);
    static constexpr gf::Vector2f PlayerSize = gf::vec(TileSize.x / 8.0f, TileSize.y * 1.20f);

    GameData(gf::ResourceManager& ressources);

    LevelData& getCurrentLevel();

    int currentLevel = 0;
    std::vector<LevelData> levels;
  };
}

#endif // LOCAL_GAME_DATA_H_
