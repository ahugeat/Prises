#include "GameState.h"

namespace pr {
  GameState::GameState() {
    player.body.b2Body = physics.engine;
  }
}
