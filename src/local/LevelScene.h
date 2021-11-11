#ifndef LOCAL_LEVEL_SCENE_H_
#define LOCAL_LEVEL_SCENE_H_

#include <gf/Action.h>
#include <gf/Scene.h>

#include "PlayerEntity.h"

namespace flo {
  struct GameHub;

  class LevelScene: public gf::Scene {
  public:
    LevelScene(GameHub& game);

    virtual void doHandleActions(gf::Window& window) override;

  private:
    GameHub& m_game;

    gf::Action m_moveUp;
    gf::Action m_moveDown;
    gf::Action m_moveLeft;
    gf::Action m_moveRight;

    PlayerEntity m_player;
  };
}

#endif // LOCAL_LEVEL_SCENE_H_
