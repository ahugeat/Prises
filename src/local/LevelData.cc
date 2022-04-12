#include "LevelData.h"

#include <cassert>

#include <gf/Log.h>
#include <gf/TmxOps.h>

namespace pr {
  namespace {
    enum LayerName {
      Walls,
    };

    LayerName toLayerName(const std::string& name) {
      if (name == "walls") {
        return LayerName::Walls;
      }

      gf::Log::debug("Unknown layer: %s\n", name.c_str());
      assert(false);
      return LayerName::Walls;
    }

    class LayersDataMaker : public gf::TmxVisitor {
    public:
      LayersDataMaker(gf::ResourceManager& resources, LevelData& data)
      : m_resources(resources)
      , m_data(data)
      {
      }

      virtual void visitTileLayer(const gf::TmxLayers& map, const gf::TmxTileLayer& layer) override {
        if (!layer.visible) {
          return;
        }

        m_data.layers.emplace_back(gf::makeTileLayer(map, layer, m_resources));
        auto name = toLayerName(layer.name);

        int k = 0;

        for (auto& cell : layer.cells) {
          int i = k % map.mapSize.width;
          int j = k / map.mapSize.width;
          assert(j < map.mapSize.height);

          ++k;

          int gid = cell.gid;

          if (gid == 0) {
            continue;
          }

          const gf::TmxTileset *tileset = map.getTileSetFromGID(gid);
          assert(tileset);
          gid = gid - tileset->firstGid;

          switch (name) {
            case LayerName::Walls:
              assert(m_data.walls.isValid(gf::vec(i, j)));
              assert(m_data.walls(gf::vec(i, j)) == WallType::None);
              assert(0 <= gid && gid <= 27);
              m_data.walls(gf::vec(i, j)) = static_cast<WallType>(gid);
              break;
          }
        }
      }

    private:
      gf::ResourceManager& m_resources;
      LevelData& m_data;
    };
  }

  LevelData::LevelData()
  : walls(gf::vec(20,20), WallType::None)
  {
  }

  LevelData LevelData::makeFromTmx(gf::ResourceManager& resources, const gf::TmxLayers& tmx) {
    LevelData data;

    LayersDataMaker maker(resources, data);
    tmx.visitLayers(maker);

    return data;
  }
}
