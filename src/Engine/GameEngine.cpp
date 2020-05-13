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
  try {
    first->handle();
  } catch (const std::runtime_error &re) {
    if (re.what() == "It was the last handler") {
      return true;
    } else {
      std::cerr << re.what();
      return false;
    }
  }
  return true;
}

std::shared_ptr<Handler> GameEngine::generateBotHandlersChain(std::shared_ptr<Player> bot) {
  std::vector<std::shared_ptr<Handler> > chain;
  int32_t populationAmount = bot->getPopulationsNumber();
  for (int32_t i = 0; i < populationAmount; ++i) {
    std::shared_ptr<Population> tempPopulation = std::move(bot->getPopulation(i));
    std::shared_ptr<Handler> link;
    int32_t x;
    int32_t y;
    int32_t dX;
    int32_t dY;
    int32_t handlerType = RandomGenerator::getInstance().randInt(0, 4);
    if (tempPopulation->GetAnimalAmount() * 10
        > Config::getInstance().getMaxAmount(tempPopulation->GetType(), tempPopulation->GetSize()) * 8) {
      handlerType = 5;
    }
    switch (handlerType) {
      case 0:link = std::make_shared<CoverMutationHandler>();
        link->setPopulation(tempPopulation);
        break;
      case 1:link = std::make_shared<SafetyMutationHandler>();
        link->setPopulation(tempPopulation);
        break;
      case 2:link = std::make_shared<SizeMutationHandler>();
        link->setPopulation(tempPopulation);
        break;
      case 3:link = std::make_shared<VelocityMutationHandler>();
        link->setPopulation(tempPopulation);
        break;
      case 4:link = std::make_shared<MoveHandler>();
        x = tempPopulation->GetXPos();
        y = tempPopulation->GetYPos();
        dX = RandomGenerator::getInstance().randInt(0, 1);
        dY = RandomGenerator::getInstance().randInt(-1, 1);
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
        link->setPopulation(tempPopulation);
        break;
      case 5:std::shared_ptr<Population> newPopulation = std::make_shared<Population>(*(tempPopulation));
        newPopulation->SetAnimalAmount(newPopulation->GetAnimalAmount() / 2);
        tempPopulation->SetAnimalAmount(tempPopulation->GetAnimalAmount() / 2);
        link = std::make_shared<MoveHandler>();
        x = tempPopulation->GetXPos();
        y = tempPopulation->GetYPos();
        dX = RandomGenerator::getInstance().randInt(-1, 1);
        dY = RandomGenerator::getInstance().randInt(-1, 1);
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
        link->setPopulation(newPopulation);
        break;
    }
    chain.push_back(link);
    if (i > 0) {
      chain[i - 1]->setNext(chain[i]);
    }
  }
}