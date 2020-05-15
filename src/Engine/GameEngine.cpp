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

void GameEngine::fillPopulationPattern(std::vector<LightPopulation> &populations) {
  if (players.empty()) {
    players.push_back(std::make_shared<Player>(std::string("Cat")));
  }

  for (const auto &player : players) {
    if (player->getPopulationsNumber() == 0) {
      player->generatePopulations();
    }

    for (const auto &population : player->GetPlayerPopulations()) {
      int32_t y = RandomGenerator::getInstance().randInt(0, map->getHeight() - 1);
      int32_t x = RandomGenerator::getInstance().randInt(0, map->getWidth() - 1);
      size_t step = 0;

      while (isPopulationExist(x, y) && step < 10) {
        y = RandomGenerator::getInstance().randInt(0, map->getHeight() - 1);
        x = RandomGenerator::getInstance().randInt(0, map->getWidth() - 1);
        std::cout << x << " " << y << std::endl;
        ++step;
      }
      std::cout << " End " << std::endl;
      std::cout << x << " " << y << std::endl;

      if (step == 10) {
        std::cerr << "Cannot generate populations" << std::endl;
      }

      population->SetXPos(x);
      population->SetYPos(y);
      (*map)[y][x]->setCurrentPopulation(population);

      populations.emplace_back(*population);
    }
  }
}

bool GameEngine::botTurn(std::shared_ptr<Player> bot) {
  try {
    generateBotHandlersChain(bot)->handle();
  } catch (const std::runtime_error &re) {
    if (std::string(re.what()) == "It was the last handler") {
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
    int32_t x = tempPopulation->GetXPos();
    int32_t y = tempPopulation->GetYPos();
    int32_t dX, dY;
    std::pair<int32_t, int32_t> pos;
    int32_t mutationType;
    int32_t handlerType = RandomGenerator::getInstance().randInt(1, 2);
    if (tempPopulation->GetAnimalAmount() * 10
        > Config::getInstance().getMaxAmount(tempPopulation->GetType(), tempPopulation->GetSize()) * 6) {
      handlerType = 3;
    }
    switch (handlerType) {
      case 1:mutationType = RandomGenerator::getInstance().randInt(0, 3);
        switch (mutationType) {
          case 0:link = std::make_shared<CoverMutationHandler>();
            break;
          case 1:link = std::make_shared<SafetyMutationHandler>();
            break;
          case 2:link = std::make_shared<SizeMutationHandler>();
            break;
          case 3:link = std::make_shared<VelocityMutationHandler>();
            break;
        }
        link->setPopulation(tempPopulation);
        break;
      case 2:link = std::make_shared<MoveHandler>();
        pos = getDestinationPos(tempPopulation);
        dX = pos.first;
        dY = pos.second;
        link->setXYPos(x + dX, y + dY);
        link->setPopulation(tempPopulation);
        if (tempPopulation->GetType() == Population::HERBIVORE) {
          (*map)[x][y]->setHerbivoreCount(0);
          (*map)[x + dX][y + dY]->setHerbivoreCount(1);
        } else {
          (*map)[x][y]->setCarnivoreCount(0);
          (*map)[x + dX][y + dY]->setCarnivoreCount(1);
        }
        break;
      case 3:pos = getDestinationPos(tempPopulation);
        dX = pos.first;
        dY = pos.second;
        if (dX == 0 && dY == 0) {
          link = std::make_shared<VelocityMutationHandler>();
          link->setPopulation(tempPopulation);
        } else {
          std::shared_ptr<Population> newPopulation = std::make_shared<Population>(*(tempPopulation));
          newPopulation->SetAnimalAmount(newPopulation->GetAnimalAmount() / 2);
          tempPopulation->SetAnimalAmount(tempPopulation->GetAnimalAmount() / 2);
          link = std::make_shared<MoveHandler>();
          link->setXYPos(x + dX, y + dY);
          link->setPopulation(newPopulation);
          if (tempPopulation->GetType() == Population::HERBIVORE) {
            (*map)[x + dX][y + dY]->setHerbivoreCount(1);
          } else {
            (*map)[x + dX][y + dY]->setCarnivoreCount(1);
          }
        }
        break;
    }
    chain.push_back(link);
    if (i > 0) {
      chain[i - 1]->setNext(chain[i]);
    }
  }
  return chain[0];
}

void GameEngine::setPlayers(std::vector<std::shared_ptr<Player> > &_players) {
  players = _players;
}

std::shared_ptr<CellType> GameEngine::getCell(size_t posX, size_t posY) {
  return (*map)[posY][posX];
}

std::shared_ptr<Population> GameEngine::getPopulation(size_t posX, size_t posY) {
  return (*map)[posY][posX]->getCurrentPopulation();
}

bool GameEngine::isPopulationExist(size_t posX, size_t posY) {
  return (*map)[posY][posX]->getCurrentPopulation() != nullptr;
}

void GameEngine::populationMove(std::shared_ptr<Population> population, int32_t x_pos, int32_t y_pos) {
  population->move(x_pos, y_pos);
}

void GameEngine::populationMutate(std::shared_ptr<Population> population, Population::MutationType type) {
  population->mutate(type);
}

void GameEngine::populationSplit(std::shared_ptr<Population> population, int32_t destination_x, int32_t destination_y) {
  population->SetAnimalAmount(population->GetAnimalAmount() / 2);
  std::shared_ptr<Population> new_population = std::make_shared<Population>(*(population));
  new_population->SetXPos(destination_x);
  new_population->SetYPos(destination_y);
  players[tempPlayer]->addNewPopulation(new_population);
}

std::pair<int32_t, int32_t> GameEngine::getDestinationPos(std::shared_ptr<Population> tempPopulation) {
  int32_t xPos = tempPopulation->GetXPos();
  int32_t yPos = tempPopulation->GetYPos();
  int32_t dX = RandomGenerator::getInstance().randInt(-1, 1);
  int32_t dY = RandomGenerator::getInstance().randInt(-1, 1);
  if (yPos + dY < 0) {
    dY = 1;
  }
  if (yPos + 1 >= map->getHeight()) {
    dY = -1;
  }
  if (dY != 0) {
    if (yPos % 2 == 1) {
      dX = RandomGenerator::getInstance().randInt(0, 1);
    } else {
      dX = RandomGenerator::getInstance().randInt(-1, 0);
    }
  }
  if (xPos + dX < 0 || xPos + dX >= map->getWidth()) {
    dX = 0;
  }
  if ((*map)[xPos + dX][yPos + dY]->getCarnivoreCount() > 0 || (*map)[xPos + dX][yPos + dY]->getHerbivoreCount() > 0) {
    dX = 0;
    dY = 0;
  }
  return std::make_pair(dX, dY);
}