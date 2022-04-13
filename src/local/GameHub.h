#ifndef LOCAL_GAME_HUB_H
#define LOCAL_GAME_HUB_H

#include <gf/GameManager.h>

#include "GameData.h"
#include "GameState.h"
#include "LevelScene.h"
#include "MenuScene.h"

namespace pr {
  struct GameHub : gf::GameManager {
    GameHub();

    GameData data;
    GameState state;

    MenuScene menu;
    LevelScene level;
  };
}

#endif // LOCAL_GAME_HUB_H
