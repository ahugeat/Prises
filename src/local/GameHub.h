#ifndef FLO_GAME_HUB_H
#define FLO_GAME_HUB_H

#include <gf/GameManager.h>

#include "GameModel.h"
#include "LevelScene.h"
#include "MenuScene.h"

namespace flo {
  struct GameHub : gf::GameManager {
    GameHub();

    GameModel model;

    MenuScene menu;
    LevelScene level;
  };
}

#endif // FLO_GAME_HUB_H
