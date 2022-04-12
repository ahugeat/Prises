#include "GameData.h"

#include <cassert>
#include <stdexcept>

namespace pr {
  GameData::GameData(gf::ResourceManager& resources) {
    for (auto & path : { "levels/level-00.tmx" }) {
      gf::TmxLayers tmx;
      tmx.loadFromFile(resources.getAbsolutePath(path));

      levels.push_back(LevelData::makeFromTmx(resources, tmx));
    }
  }

  LevelData& GameData::getCurrentLevel() {
    if (currentLevel < 0 || currentLevel >= static_cast<int>(levels.size())) {
      throw std::runtime_error("[GameData] invalid level: " + std::to_string(currentLevel));
    }

    return levels[currentLevel];
  }

}
