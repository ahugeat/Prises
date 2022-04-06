#ifndef LOCAL_GAME_MODEL_H_
#define LOCAL_GAME_MODEL_H_

#include <string>
#include <vector>

#include <gf/Vector.h>
#include <gf/VectorOps.h>

namespace pr {
  enum class TileType: char{
    Wall = '#',
    Empty = ' ',
  };

  struct LevelModel {
    LevelModel(std::initializer_list<std::string> tilesList);

    const TileType& tileAt(int col, int row) const;

    std::vector<TileType> tiles;
    gf::Vector2i size;
  };

  struct GameModel {
    static constexpr gf::Vector2i TileSize = gf::vec(128, 128);
    static constexpr gf::Vector2i WorldSize = gf::vec(1024, 1024) * TileSize;
    static constexpr gf::Vector2i PlayerSize = TileSize / 2;

    GameModel();

    const LevelModel& getCurrentLevel() const;

    int currentLevel;
    std::vector<LevelModel> levels;
  };
}

#endif // LOCAL_GAME_MODEL_H_
