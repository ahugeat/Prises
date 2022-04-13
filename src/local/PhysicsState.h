#ifndef LOCAL_PHYSICS_STATE_H_
#define LOCAL_PHYSICS_STATE_H_

#include <gfb2d/PhysicsModel.h>

namespace pr {
  struct PhysicsState {
    PhysicsState();

    gfb2d::PhysicsModel engine;
  };
}

#endif // LOCAL_PHYSICS_STATE_H_
