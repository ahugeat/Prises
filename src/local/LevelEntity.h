#ifndef LOCAL_MAP_ENTITY_H_
#define LOCAL_MAP_ENTITY_H_

#include <gf/Entity.h>

namespace pr {
  struct GameModel;

  class LevelEntity: public gf::Entity {
  public:
    LevelEntity(GameModel& model);

    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

  private:
    GameModel& m_model;
  };
}


#endif // LOCAL_MAP_ENTITY_H_
