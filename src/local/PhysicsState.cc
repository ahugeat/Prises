#include "PhysicsState.h"

namespace pr {
  namespace {
    constexpr float PhysicsScale = 0.2f;
    constexpr gf::Vector2f PhysicsGravity = gf::vec(0.0f, 0.0f);
  }


  PhysicsState::PhysicsState()
  : engine(PhysicsScale, PhysicsGravity)
  {

  }
}
