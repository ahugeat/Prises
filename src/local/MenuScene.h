#ifndef FLO_MENU_SCENE_H_
#define FLO_MENU_SCENE_H_

#include <gf/Scene.h>

#include "MenuEntity.h"

namespace flo {
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

#endif // FLO_MENU_SCENE_H_
