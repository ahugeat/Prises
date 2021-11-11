#ifndef LOCAL_MAP_ENTITY_H_
#define LOCAL_MAP_ENTITY_H_

#include <gf/Entity.h>

namespace flo {
  struct GameModel;

  class MapEntity: public gf::Entity {
  public:
    MapEntity(GameModel& model);

    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

  private:
    GameModel& m_model;
  };
}


#endif // LOCAL_MAP_ENTITY_H_
