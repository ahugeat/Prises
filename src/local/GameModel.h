#ifndef LOCAL_GAME_MODEL_H_
#define LOCAL_GAME_MODEL_H_

#include <string>

#include <gf/Vector.h>
#include <gf/VectorOps.h>

namespace flo {
  enum class TileType: char{
    Wall = '#',
    Empty = ' ',
  };

  using TileMatrix = std::vector<std::vector<TileType>>;

  struct LevelModel {
    LevelModel(std::initializer_list<std::string> tilesList);

    TileMatrix tiles;
    gf::Vector2i size;
  };

  struct GameModel {
    static constexpr gf::Vector2i TileSize = gf::vec(128, 128);
    static constexpr gf::Vector2i WorldSize = gf::vec(1024, 1024) * TileSize;

    GameModel();

    int currentLevel;
    std::vector<LevelModel> levels;
  };
}

#endif // LOCAL_GAME_MODEL_H_
