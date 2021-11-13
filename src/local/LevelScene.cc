#include "LevelScene.h"

#include <gf/Direction.h>

#include "GameHub.h"
#include "GameModel.h"

namespace flo {
  LevelScene::LevelScene(GameHub& game)
  : gf::Scene(game.model.getCurrentLevel().size * GameModel::TileSize)
  , m_game(game)
  , m_moveUp("Move up")
  , m_moveDown("Move down")
  , m_moveLeft("Move left")
  , m_moveRight("Move right")
  , m_map(game.model)
  , m_player(game.model) {
    // Entities
    addWorldEntity(m_map);
    addWorldEntity(m_player);

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

    // Views
    gf::Vector2f viewSize = game.model.getCurrentLevel().size * GameModel::TileSize;
    setWorldViewSize(viewSize);
    setWorldViewCenter(viewSize / 2);
  }

  void LevelScene::doHandleActions(gf::Window& window) {
    gf::unused(window);

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

  void LevelScene::loadNextLevel() {
    ++m_game.model.currentLevel;
    auto level = m_game.model.getCurrentLevel();

    setFramebufferSize(level.size * GameModel::TileSize);
  }
}
