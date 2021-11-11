#include "GameHub.h"

#include "config.h"

namespace flo {
  GameHub::GameHub()
  : gf::GameManager("Game Flo", { GAME_DATADIR, GAME_SOURCE_DATADIR })
  , menu(*this) {
    pushScene(menu);
  }
}
