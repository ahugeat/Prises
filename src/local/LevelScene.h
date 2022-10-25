#ifndef LOCAL_LEVEL_SCENE_H_
#define LOCAL_LEVEL_SCENE_H_

#include <gf/Action.h>
#include <gf/Scene.h>

#include "vendor/gf-box2d/gfb2d/PhysicsDebugger.h"

#include "LevelEntity.h"
#include "PlayerEntity.h"

namespace pr {
  struct GameHub;

  class LevelScene: public gf::Scene {
  public:
    LevelScene(GameHub& game);

  private:
    virtual void doHandleActions(gf::Window& window) override;
    virtual void doUpdate(gf::Time time) override;

    void loadLevel();

  private:
    GameHub& m_game;

    gf::Action m_moveUp;
    gf::Action m_moveDown;
    gf::Action m_moveLeft;
    gf::Action m_moveRight;

    LevelEntity m_map;
    PlayerEntity m_player;

    gfb2d::PhysicsDebugger m_b2Debug;
  };
}

#endif // LOCAL_LEVEL_SCENE_H_
