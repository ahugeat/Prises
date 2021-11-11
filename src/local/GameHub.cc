#include "GameHub.h"

#include "config.h"

namespace flo {
  GameHub::GameHub()
  : gf::GameManager("Game Flo", { GAME_DATA_DIR, GAME_SOURCE_DATA_DIR })
  , menu(*this)
  , level(*this) {
    pushScene(menu);
  }
}
