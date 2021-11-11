#ifndef FLO_GAME_HUB_H
#define FLO_GAME_HUB_H

#include <gf/GameManager.h>

#include "MenuScene.h"

namespace flo {
  struct GameHub : gf::GameManager {
    GameHub();

    MenuScene menu;
  };
}

#endif // FLO_GAME_HUB_H
