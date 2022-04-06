#ifndef LOCAL_PLAYER_ENTITY_H_
#define LOCAL_PLAYER_ENTITY_H_

#include <gf/Direction.h>
#include <gf/Entity.h>
#include <gf/Vector.h>

namespace pr {
  struct GameModel;

  class PlayerEntity: public gf::Entity {
  public:
    PlayerEntity(GameModel& model);

    virtual void update(gf::Time time) override;
    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

    void move(gf::Direction direction);

  private:
    GameModel& m_model;

    gf::Vector2f m_position;
    gf::Vector2f m_direction;
  };
}

#endif // LOCAL_PLAYER_ENTITY_H_
