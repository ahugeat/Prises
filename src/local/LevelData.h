#ifndef LOCAL_LEVEL_DATA_H_
#define LOCAL_LEVEL_DATA_H_

#include <gf/Array2D.h>
#include <gf/ResourceManager.h>
#include <gf/TileLayer.h>
#include <gf/Tmx.h>

namespace pr {
  enum class WallType {
    None              = -1,

    PlainWallEast     = 0,
    PlainWallNorth    = 1,
    PlainWallSouth    = 2,
    PlainWallWest     = 3,
    PlainCornerEast   = 4,
    PlainCornerNorth  = 5,
    PlainCornerSouth  = 6,
    PlainCornerWest   = 7,

    HalfWallEast      = 8,
    HalfWallNorth     = 9,
    HalfWallSouth     = 10,
    HalfWallWest      = 11,
    HalfCornerEast    = 12,
    HalfCornerNorth   = 13,
    HalfCornerSouth   = 14,
    HalfCornerWest    = 15,

    CurveEast         = 16,
    CurveNorth        = 17,
    CurveSouth        = 18,
    CurveWest         = 19,

    HalfCurveEast     = 20,
    HalfCurveNorth    = 21,
    HalfCurveSouth    = 22,
    HalfCurveWest     = 23,

    BattlementEast     = 24,
    BattlementNorth    = 25,
    BattlementSouth    = 26,
    BattlementWest     = 27
  };

  struct LevelData {
    LevelData();
    ~LevelData() = default;

    LevelData(const LevelData&) = delete;
    LevelData(LevelData&&) = default;

    LevelData& operator=(const LevelData&) = delete;
    LevelData& operator=(LevelData&&) = default;

    gf::Vector2i levelSize;

    gf::Array2D<WallType, int> walls;
    std::vector<gf::TileLayer> layers;

    static LevelData makeFromTmx(gf::ResourceManager& resources, const gf::TmxLayers& tmx);
  };
}

#endif // LOCAL_LEVEL_DATA_H_
