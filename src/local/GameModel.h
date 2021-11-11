#ifndef LOCAL_GAME_MODEL_H_
#define LOCAL_GAME_MODEL_H_

#include <gf/Vector.h>

namespace flo {
  struct GameModel {
    static constexpr gf::Vector2i WorldSize = gf::vec(1024, 1024);
  };
}

#endif // LOCAL_GAME_MODEL_H_
