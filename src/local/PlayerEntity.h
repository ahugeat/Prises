#ifndef LOCAL_PLAYER_ENTITY_H_
#define LOCAL_PLAYER_ENTITY_H_

#include <gf/Direction.h>
#include <gf/Entity.h>
#include <gf/Vector.h>

namespace pr {
  struct GameData;

  class PlayerEntity: public gf::Entity {
  public:
    PlayerEntity(GameData& model);

    virtual void update(gf::Time time) override;
    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

    void move(gf::Direction direction);

  private:
    GameData& m_model;

    gf::Vector2f m_position;
    gf::Vector2f m_direction;
  };
}

#endif // LOCAL_PLAYER_ENTITY_H_
