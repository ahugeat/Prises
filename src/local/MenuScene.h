#ifndef LOCAL_MENU_SCENE_H_
#define LOCAL_MENU_SCENE_H_

#include <gf/Scene.h>

#include "MenuEntity.h"

namespace pr {
  struct GameHub;

  class MenuScene: public gf::Scene {
  public:
    MenuScene(GameHub& game);

  private:
    void doProcessEvent(gf::Event& event) override;
    void doHandleActions(gf::Window& window) override;
    void doUpdate(gf::Time time) override;

  private:
    GameHub& m_game;

    MenuChoice m_choice;
    MenuEntity m_menu;
  };
}

#endif // LOCAL_MENU_SCENE_H_
