#include "GameHub.h"

#include "config.h"

namespace pr {
  GameHub::GameHub()
  : gf::GameManager("Prises", { GAME_RELATIVE_DATA_DIR, GAME_DATA_DIR })
  , data(resources)
  , menu(*this)
  , level(*this) {
    pushScene(level);
  }
}
