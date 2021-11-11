#ifndef FLO_MENU_SCENE_H_
#define FLO_MENU_SCENE_H_

#include <gf/Scene.h>
#include <gf/Action.h>

namespace flo {
  struct GameHub;

  class MenuScene: public gf::Scene {
  public:
    MenuScene(GameHub& game);

  private:
    void doHandleActions(gf::Window& window) override;

  private:
    GameHub& m_game;

    // gf::Action m_startAction;
    // gf::Action m_fullscreenAction;
  };
}

#endif // FLO_MENU_SCENE_H_
