#include "LevelScene.h"

#include <gf/Direction.h>

#include "GameHub.h"
#include "GameData.h"

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

  void LevelScene::doUpdate(gf::Time time) {
    m_game.state.physics.engine.update(time);
  }

  void LevelScene::loadLevel() {
    const auto& level = m_game.data.getCurrentLevel();

    // Update views
    gf::Vector2f viewSize = level.levelSize * GameData::TileSize;
    setWorldViewSize(viewSize);
    setWorldViewCenter(viewSize * 0.5f);
  }
}
