#ifndef FLO_GAME_HUB_H
#define FLO_GAME_HUB_H

#include <gf/GameManager.h>

#include "GameData.h"
#include "LevelScene.h"
#include "MenuScene.h"

namespace pr {
  struct GameHub : gf::GameManager {
    GameHub();

    GameData data;

    MenuScene menu;
    LevelScene level;
  };
}

#endif // FLO_GAME_HUB_H
