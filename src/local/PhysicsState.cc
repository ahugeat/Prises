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

  b2Body *PhysicsState::createPlayerBody(const gf::Vector2f& position, float radius) {
    auto body = engine.createSimpleBody(position, 0.0f, gfb2d::BodyType::Dynamic);
    engine.createCircleFixture(body, radius);

    return body;
  }

  b2Body* PhysicsState::createWallBody(const gf::Polygon& bounds, const gf::Vector2f& offset) {
    auto body = engine.createSimpleBody(bounds.getCenter() + offset, 0.0f, gfb2d::BodyType::Static);

    gf::Polygon fixtureBounds;
    for(const auto& point : bounds) {
      fixtureBounds.addPoint(point - bounds.getCenter());
    }
    engine.createPolygonFixture(body, fixtureBounds);

    return body;
  }

}
