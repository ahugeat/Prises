#ifndef LOCAL_PLAYER_ENTITY_H_
#define LOCAL_PLAYER_ENTITY_H_

#include <gf/Direction.h>
#include <gf/Entity.h>
#include <gf/Vector.h>

#include <box2d/b2_body.h>

namespace pr {
  struct GameData;
  struct GameHub;

  class PlayerEntity: public gf::Entity {
  public:
    PlayerEntity(GameHub& hub);

    virtual void update(gf::Time time) override;
    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

    void move(gf::Direction direction);

  private:
    GameData& m_model;

    gf::Vector2f m_position;
    gf::Vector2f m_direction;

    b2Body* m_body;
  };
}

#endif // LOCAL_PLAYER_ENTITY_H_
