#ifndef LOCAL_MAP_ENTITY_H_
#define LOCAL_MAP_ENTITY_H_

#include <gf/Entity.h>

namespace pr {
  struct GameData;

  class LevelEntity: public gf::Entity {
  public:
    LevelEntity(GameData& model);

    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

  private:
    GameData& m_model;
  };
}


#endif // LOCAL_MAP_ENTITY_H_
