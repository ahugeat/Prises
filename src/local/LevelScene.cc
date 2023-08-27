#include "LevelScene.h"

#include <list>

#include <gf/Cells.h>
#include <gf/Direction.h>
#include <gf/Log.h>

#include "GameHub.h"
#include "GameData.h"

namespace {

  std::list<gf::Polygon> getWallBounds(const gf::Vector2f& tilePosition, pr::WallType type) {
    constexpr gf::Vector2i Steps = pr::GameData::TileSize / 8;

    std::list<gf::Polygon> bounds;
    switch (type) {
      case pr::WallType::PlainWallEast:
      case pr::WallType::HalfWallEast:
      case pr::WallType::BattlementEast:
      {
        gf::Polygon bound;
        bound.addPoint(tilePosition + (Steps * gf::vec(0, 4)));
        bound.addPoint(tilePosition + (Steps * gf::vec(1, 5)));
        bound.addPoint(tilePosition + (Steps * gf::vec(5, 1)));
        bound.addPoint(tilePosition + (Steps * gf::vec(4, 0)));
        bounds.push_back(bound);
        break;
      }

      case pr::WallType::PlainCornerEast:
      case pr::WallType::HalfCornerEast:
      case pr::WallType::CurveEast:
      case pr::WallType::HalfCurveEast:
      {
        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(0, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 8)));
          bound.addPoint(tilePosition + (Steps * gf::vec(5, 7)));
          bound.addPoint(tilePosition + (Steps * gf::vec(1, 3)));
          bounds.push_back(bound);
        }

        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(1, 3)));
          bound.addPoint(tilePosition + (Steps * gf::vec(2, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(5, 1)));
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 0)));
          bounds.push_back(bound);
        }

        break;
      }

      case pr::WallType::PlainWallWest:
      case pr::WallType::HalfWallWest:
      case pr::WallType::BattlementWest:
      {
        gf::Polygon bound;
        bound.addPoint(tilePosition + (Steps * gf::vec(3, 7)));
        bound.addPoint(tilePosition + (Steps * gf::vec(4, 8)));
        bound.addPoint(tilePosition + (Steps * gf::vec(8, 4)));
        bound.addPoint(tilePosition + (Steps * gf::vec(7, 3)));
        bounds.push_back(bound);
        break;
      }

      case pr::WallType::PlainCornerWest:
      case pr::WallType::HalfCornerWest:
      case pr::WallType::CurveWest:
      case pr::WallType::HalfCurveWest:
      {
        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(3, 7)));
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 8)));
          bound.addPoint(tilePosition + (Steps * gf::vec(8, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(7, 3)));
          bounds.push_back(bound);
        }

        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(3, 1)));
          bound.addPoint(tilePosition + (Steps * gf::vec(6, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(7, 3)));
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 0)));
          bounds.push_back(bound);
        }

        break;
      }

      case pr::WallType::PlainWallNorth:
      case pr::WallType::HalfWallNorth:
      case pr::WallType::BattlementNorth:
      {
        gf::Polygon bound;
        bound.addPoint(tilePosition + (Steps * gf::vec(0, 4)));
        bound.addPoint(tilePosition + (Steps * gf::vec(4, 8)));
        bound.addPoint(tilePosition + (Steps * gf::vec(5, 7)));
        bound.addPoint(tilePosition + (Steps * gf::vec(1, 3)));
        bounds.push_back(bound);
        break;
      }

      case pr::WallType::PlainCornerNorth:
      case pr::WallType::HalfCornerNorth:
      case pr::WallType::CurveNorth:
      case pr::WallType::HalfCurveNorth:
      {
        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(0, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 8)));
          bound.addPoint(tilePosition + (Steps * gf::vec(5, 7)));
          bound.addPoint(tilePosition + (Steps * gf::vec(1, 3)));
          bounds.push_back(bound);
        }

        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 6)));
          bound.addPoint(tilePosition + (Steps * gf::vec(5, 7)));
          bound.addPoint(tilePosition + (Steps * gf::vec(8, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(7, 3)));
          bounds.push_back(bound);
        }

        break;
      }

      case pr::WallType::PlainWallSouth:
      case pr::WallType::HalfWallSouth:
      case pr::WallType::BattlementSouth:
      {
        gf::Polygon bound;
        bound.addPoint(tilePosition + (Steps * gf::vec(3, 1)));
        bound.addPoint(tilePosition + (Steps * gf::vec(7, 5)));
        bound.addPoint(tilePosition + (Steps * gf::vec(8, 4)));
        bound.addPoint(tilePosition + (Steps * gf::vec(4, 0)));
        bounds.push_back(bound);
        break;
      }

      case pr::WallType::PlainCornerSouth:
      case pr::WallType::HalfCornerSouth:
      case pr::WallType::CurveSouth:
      case pr::WallType::HalfCurveSouth:
      {
        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(3, 1)));
          bound.addPoint(tilePosition + (Steps * gf::vec(7, 5)));
          bound.addPoint(tilePosition + (Steps * gf::vec(8, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 0)));
          bounds.push_back(bound);
        }

        {
          gf::Polygon bound;
          bound.addPoint(tilePosition + (Steps * gf::vec(0, 4)));
          bound.addPoint(tilePosition + (Steps * gf::vec(1, 5)));
          bound.addPoint(tilePosition + (Steps * gf::vec(4, 2)));
          bound.addPoint(tilePosition + (Steps * gf::vec(3, 1)));
          bounds.push_back(bound);
        }

        break;
      }

      default:
        gf::Log::warning("No bounds for wall type: %d\n", static_cast<int>(type));
        break;
    }

    return bounds;
  }

}

namespace pr {
  LevelScene::LevelScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_moveUp("Move up")
  , m_moveDown("Move down")
  , m_moveLeft("Move left")
  , m_moveRight("Move right")
  , m_map(game.data)
  , m_player(game.state.physics)
  , m_b2Debug(game.state.physics.engine) {
    // Entities
    addWorldEntity(m_map);
    addWorldEntity(m_player);
    addWorldEntity(m_b2Debug);

    m_b2Debug.setDebug(true);

    // Actions
    auto registerMoveAction = [this](gf::Action& action, std::initializer_list<gf::Scancode> scancodes) {
      action.setContinuous();
      for (auto scancode: scancodes) {
        action.addScancodeKeyControl(scancode);
      }
      addAction(action);
    };

    registerMoveAction(m_moveUp, { gf::Scancode::W, gf::Scancode::Up });
    registerMoveAction(m_moveDown, { gf::Scancode::S, gf::Scancode::Down });
    registerMoveAction(m_moveLeft, { gf::Scancode::A, gf::Scancode::Left });
    registerMoveAction(m_moveRight, { gf::Scancode::D, gf::Scancode::Right });

    setClearColor(gf::Color::Black);

    // Load first level (TODO: remove this when the menu will be added)
    loadLevel();

    addModel(game.state.physics.engine);
  }

  void LevelScene::doHandleActions([[maybe_unused]] gf::Window& window) {
    if (m_moveUp.isActive()) {
      m_player.move(gf::Direction::Up);
    }
    if (m_moveDown.isActive()) {
      m_player.move(gf::Direction::Down);
    }
    if (m_moveLeft.isActive()) {
      m_player.move(gf::Direction::Left);
    }
    if (m_moveRight.isActive()) {
      m_player.move(gf::Direction::Right);
    }
  }

  void LevelScene::loadLevel() {
    const auto& level = m_game.data.getCurrentLevel();

    // Update views
    gf::Vector2f viewSize = level.levelSize * GameData::TileSize;
    setWorldViewSize(viewSize);
    setWorldViewCenter(viewSize * 0.5f);

    // Define wall physics
    for (int row = 0; row < level.levelSize.row; ++row) {
      for (int col = 0; col < level.levelSize.col; ++col) {
        WallType tile = level.walls(gf::vec(col, row));

        if (tile != WallType::None) {
          gf::StaggeredCells cells(GameData::TileSize, gf::CellAxis::Y, gf::CellIndex::Odd);
          gf::RectF cellBounds = cells.computeCellBounds(gf::vec(col, row));

          auto bounds = getWallBounds(cellBounds.getTopLeft(), tile);
          for (const auto& bound: bounds) {
            m_game.state.physics.createWallBody(bound, gf::vec(0.0f, 3.0f * 128.0f));
          }
        }
      }
    }
  }
}
