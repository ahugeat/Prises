#include "MenuScene.h"

#include "GameHub.h"

namespace flo {
  MenuScene::MenuScene(GameHub& game)
  : gf::Scene(game.getRenderer().getSize())
  , m_game(game)
  , m_choice(MenuChoice::None)
  , m_menu(game.resources, m_choice) {
    addHudEntity(m_menu);
  }

  void MenuScene::doProcessEvent(gf::Event& event) {
    switch (event.type) {
      case gf::EventType::MouseMoved:
        m_menu.pointTo(m_game.getRenderer().mapPixelToCoords(event.mouseCursor.coords));
        break;

      case gf::EventType::MouseButtonPressed:
        m_menu.pointTo(m_game.getRenderer().mapPixelToCoords(event.mouseButton.coords));
        m_menu.triggerAction();
        break;

      default:
        break;
    }
  }

  void MenuScene::doHandleActions(gf::Window& window) {
    gf::unused(window);
  }

  void MenuScene::doUpdate(gf::Time time) {
    gf::unused(time);

    switch (m_choice) {
      case MenuChoice::None:
        break;
      case MenuChoice::Start:
        // Loading next scene...
        break;
      case MenuChoice::Quit:
        m_game.popScene();
        break;
    }

    m_choice = MenuChoice::None;
  }
}
