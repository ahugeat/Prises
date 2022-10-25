#include "PhysicsState.h"

#include "GameData.h"

namespace pr {
  namespace {
    constexpr float PhysicsScale = 0.2f;
    constexpr gf::Vector2f PhysicsGravity = gf::vec(0.0f, 0.0f);
  }


  PhysicsState::PhysicsState()
  : engine(PhysicsScale, PhysicsGravity)
  {

  }

  b2Body *PhysicsState::createPlayerBody(const gf::Vector2f& position, float angle) {
    auto body = engine.createSimpleBody(position, angle, gfb2d::BodyType::Dynamic);
    engine.createCircleFixture(body, GameData::PlayerSize.width * 0.5f);

    return body;
  }
}
