#include "GameEngine.h"

void GameEngine::generateMap() {
  int32_t height = RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHeight());
  int32_t width = RandomGenerator::getInstance().randNormalInt(Config::getInstance().getWidth());

  map = std::make_shared<Map>(height, width);
  map->generate();
}

void GameEngine::fillMapPattern(std::vector<std::vector<int32_t> > &cells) {
  if (map == nullptr) {
    generateMap();
  }

  cells.assign(map->getHeight(), std::vector<int32_t>(map->getWidth()));

  for (size_t row = 0; row < map->getHeight(); ++row) {
    for (size_t column = 0; column < map->getWidth(); ++column) {
      cells[row][column] = static_cast<int32_t>((*map)[row][column]->getType());
    }
  }
}

bool GameEngine::botTurn(std::shared_ptr<Handler> first) {
  try{
    first->handle();
  } catch (const std::runtime_error& re) {
    if (re.what() == "It was the last handler"){
      return true;
    }else {
      std::cerr << re.what();
      return false;
    }
  }
  return true;
}

std::shared_ptr<Handler> GameEngine::generateBotHandlersChain(std::shared_ptr<Player> bot) {
  std::vector<std::shared_ptr<Handler> > chain;
  for (int i = 0; i < bot->getPopulationsNumber(); ++i) {
    std::shared_ptr<Handler> link;
    int32_t handlerType = RandomGenerator::getInstance().randInt(0, 5);
    switch (handlerType) {
      case 0:link = std::make_shared<CoverMutationHandler>();
        break;
      case 1:link = std::make_shared<SafetyMutationHandler>();
        break;
      case 2:link = std::make_shared<SizeMutationHandler>();
        break;
      case 3:link = std::make_shared<VelocityMutationHandler>();
        break;
      case 4:
        link = std::make_shared<MoveHandler>();
        int x = bot->getPopulation(i)->GetXPos();
        int y = bot->getPopulation(i)->GetYPos();
        int dX = RandomGenerator::getInstance().randInt(-1, 1);
        int dY = RandomGenerator::getInstance().randInt(-1, 1);
        if (dX == 0 && dY == 0) {
          dX = 1;
          dY = -1;
        }
        if (x + dX < 0) {
          dX = 1;
        }
        if (x >= map->getWidth()) {
          dX = -1;
        }
        if (y + dY < 0) {
          dY = 1;
        }
        if (y >= map->getHeight()) {
          dY = -1;
        }
        link->setXYPos(x + dX, y + dY);
        break;
        /*
      case 5:
        link = std::make_shared<MoveHandler>();
        int x = bot->getPopulation(i)->GetXPos();
        int y = bot->getPopulation(i)->GetYPos();
        int dX = RandomGenerator::getInstance().randInt(-1, 1);
        int dY = RandomGenerator::getInstance().randInt(-1, 1);
        if (dX == 0 && dY == 0) {
          dX = 1;
          dY = -1;
        }
        if (x + dX < 0) {
          dX = 1;
        }
        if (x >= map->getWidth()) {
          dX = -1;
        }
        if (y + dY < 0) {
          dY = 1;
        }
        if (y >= map->getHeight()) {
          dY = -1;
        }
        link->setXYPos(x + dX, y + dY);
        break;
         */
    }
    chain.push_back(link);
    chain[i]->setPopulation(bot->getPopulation(i));
    if (i > 0) {
      chain[i - 1]->setNext(chain[i]);
    }
  }
}