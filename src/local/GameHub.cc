#include "GameHub.h"

#include "config.h"

namespace pr {
  GameHub::GameHub()
  : gf::GameManager("Game Flo", { GAME_RELATIVE_DATA_DIR, GAME_DATA_DIR })
  , menu(*this)
  , level(*this) {
    pushScene(level);
  }
}
