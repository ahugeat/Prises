#include "GameModel.h"

#include <cassert>

namespace flo {
  LevelModel::LevelModel(std::initializer_list<std::string> tilesList) {
    size = gf::vec(tilesList.begin()->size(), tilesList.size());

    assert(size.row < size.col);

    tiles.resize(size.row);
    auto it = tilesList.begin();
    for (int row = 0; row < size.row; ++row, ++it) {
      assert(it != tilesList.end());

      tiles[row].resize(size.col);
      for (int col = 0; col < size.col; ++col) {
        tiles[row][col] = static_cast<TileType>((*it)[col]);
      }
    }
  }

  GameModel::GameModel() {
    currentLevel = 0;
    levels = {
      {
        "##########",
        "#        #",
        "#        #",
        "#        #",
        "##########",
      }
    };
  }

}
