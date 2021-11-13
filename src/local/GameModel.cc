#include "GameModel.h"

#include <cassert>

namespace flo {
  LevelModel::LevelModel(std::initializer_list<std::string> tilesList)
  : size(gf::vec(tilesList.begin()->size(), tilesList.size())) {
    assert(size.row < size.col);

    for (const auto& row: tilesList) {
      for (std::size_t i = 0; i < row.size(); ++i) {
        tiles.push_back(static_cast<TileType>(row[i]));
      }
    }

    assert(static_cast<int>(tiles.size()) == size.row * size.col);
  }

  const TileType& LevelModel::tileAt(int col, int row) const {
    return tiles.at(row * size.col + col);
  }

  GameModel::GameModel() {
    currentLevel = 0;
    levels = {
      {
        "##########",
        "#        #",
        "#  #     #",
        "#        #",
        "##########",
      }
    };
  }

}
