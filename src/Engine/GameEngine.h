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
  void fillPopulationPattern(std::vector<LightPopulation> &populations);

  bool botTurn(std::shared_ptr<Player> bot);

  void setPlayers(std::vector<std::shared_ptr<Player> >& _players);

  std::shared_ptr<CellType> getCell(size_t posX, size_t posY);
  std::shared_ptr<Population> getPopulation(size_t posX, size_t posY);

  bool isPopulationExist(size_t posX, size_t posY);

  void populationMove(std::shared_ptr<Population> population, int32_t x_pos, int32_t y_pos);
  void populationSplit(std::shared_ptr<Population> population, int32_t destination_x, int32_t destination_y);
  void populationMutate(std::shared_ptr<Population> population, Population::MutationType type);

 private:
  std::shared_ptr<Map> map;
  std::vector<std::shared_ptr<Player> > players;
  int32_t tempPlayer;
  std::shared_ptr<Handler> generateBotHandlersChain(std::shared_ptr<Player> bot);
};
