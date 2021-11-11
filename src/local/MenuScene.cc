#include "MenuScene.h"

#include "GameHub.h"

namespace flo {
  MenuScene::MenuScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game) {

  }

  void MenuScene::doHandleActions(gf::Window& window) {

  }
}
