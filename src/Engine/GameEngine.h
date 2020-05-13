#pragma once

#include <memory>
#include <vector>

#include "Map/Map.h"
#include "Animals/Population.h"
#include "util/Config.h"
#include "util/RandomGenerator.h"
#include "Player/Player.h"
#include "Handler/Handler.h"
#include "Handler/CoverMutationHandler.h"
#include "Handler/MoveHandler.h"
#include "Handler/SafetyMutationHandler.h"
#include "Handler/SizeMutationHandler.h"
#include "Handler/VelocityMutationHandler.h"

class GameEngine {
 public:
  GameEngine() = default;

  void generateMap();

  void fillMapPattern(std::vector<std::vector<int32_t> > &cells);

  bool botTurn(std::shared_ptr<Handler> first);

 private:
  std::shared_ptr<Map> map;
  std::vector<std::shared_ptr<Player> > players;
  std::shared_ptr<Handler> generateBotHandlersChain(std::shared_ptr<Player> bot);
};
