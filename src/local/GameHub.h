#ifndef FLO_GAME_HUB_H
#define FLO_GAME_HUB_H

#include <gf/GameManager.h>

#include "MenuScene.h"
#include "LevelScene.h"

namespace flo {
  struct GameHub : gf::GameManager {
    GameHub();

    MenuScene menu;
    LevelScene level;
  };
}

#endif // FLO_GAME_HUB_H
