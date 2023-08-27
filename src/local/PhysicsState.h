#ifndef LOCAL_PHYSICS_STATE_H_
#define LOCAL_PHYSICS_STATE_H_

#include <gfb2d/PhysicsModel.h>

namespace pr {
  struct PhysicsState {
    PhysicsState();

    b2Body* createPlayerBody(const gf::Vector2f& position, float radius);
    b2Body* createWallBody(const gf::Polygon& bounds, const gf::Vector2f& offset);

    gfb2d::PhysicsModel engine;
  };
}

#endif // LOCAL_PHYSICS_STATE_H_
