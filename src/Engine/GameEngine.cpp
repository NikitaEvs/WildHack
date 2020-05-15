#include "GameEngine.h"

GameEngine::GameEngine() {
  currentPlayer = registerPlayer();
  botID = registerPlayer();

  maxStep = Config::getInstance().getMaxStepCount();
  currentStep = 0;

  nextStep();
}

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
  for (const auto& player : players) {
    if (player -> getPopulationsNumber() == 0) {
      player -> generatePopulations();
    }

    for (const auto& population : player -> GetPlayerPopulations()) {
      int32_t y = RandomGenerator::getInstance().randInt(0, map -> getHeight() - 1);
      int32_t x = RandomGenerator::getInstance().randInt(0, map -> getWidth() - 1);
      size_t step = 0;

      while(isPopulationExist(x, y) && step < 10) {
        y = RandomGenerator::getInstance().randInt(0, map -> getHeight() - 1);
        x = RandomGenerator::getInstance().randInt(0, map -> getWidth() - 1);
        std::cout << x << " " << y << std::endl;
        ++step;
      }
      std::cout << " End " << std::endl;
      std::cout << x << " " << y << std::endl;


      if (step == 10) {
        std::cerr << "Cannot generate populations" << std::endl;
      }

      population -> SetXPos(x);
      population -> SetYPos(y);
      (*map)[y][x] -> setCurrentPopulation(population);

      populations.emplace_back(*population);
    }
  }
}

void GameEngine::getPopulationPattern(std::vector<LightPopulation> &populations) {
  for (const auto& player : players) {
    for (const auto &population : player->GetPlayerPopulations()) {
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
    std::pair<int32_t , int32_t> pos;
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
        pos = getDestinationPos(tempPopulation);
        dX = pos.first;
        dY = pos.second;
        link->setXYPos(x + dX, y + dY);
        link->setPopulation(tempPopulation);
        break;
      case 5:
        std::shared_ptr<Population> newPopulation = std::make_shared<Population>(*(tempPopulation));
        newPopulation->SetAnimalAmount(newPopulation->GetAnimalAmount() / 2);
        tempPopulation->SetAnimalAmount(tempPopulation->GetAnimalAmount() / 2);
        link = std::make_shared<MoveHandler>();
        pos = getDestinationPos(newPopulation);
        dX = pos.first;
        dY = pos.second;
        link->setXYPos(x + dX, y + dY);
        link->setPopulation(newPopulation);
        break;
    }
    chain.push_back(link);
    if (i > 0) {
      chain[i - 1]->setNext(chain[i]);
    }
  }
  return chain[0];
}

void GameEngine::setPlayers(std::vector<std::shared_ptr<Player> >& _players) {
  players = _players;
}

std::shared_ptr<CellType> GameEngine::getCell(size_t posX, size_t posY) {
  if ((posX >= 0) && (posY >= 0) && (posX < map -> getWidth()) && (posY < map -> getHeight())) {
    return (*map)[posY][posX];
  } else {
    return nullptr;
  }
}

std::shared_ptr<Population> GameEngine::getPopulation(size_t posX, size_t posY) {
  return (*map)[posY][posX] -> getCurrentPopulation();
}

int32_t GameEngine::getCurrentID() {
  return currentPlayer;
}

std::vector<std::shared_ptr<LightPlayer> > GameEngine::getLightPlayers() {
  std::vector<std::shared_ptr<LightPlayer> > lightPlayers;

  for (const auto & player : players) {
    lightPlayers.push_back(std::make_shared<LightPlayer>(*player));
  }

  return lightPlayers;
}

bool GameEngine::isPopulationExist(size_t posX, size_t posY) {
  return (*map)[posY][posX] -> getCurrentPopulation() != nullptr;
}

void GameEngine::populationMove(std::shared_ptr<Population> population, int32_t x_pos, int32_t y_pos) {
  (*map)[population -> GetYPos()][population -> GetXPos()] -> setCurrentPopulation(nullptr);
  (*map)[y_pos][x_pos] -> setCurrentPopulation(population);

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
  players[currentPlayer]->addNewPopulation(new_population);
}

int32_t GameEngine::registerPlayer(const std::string& name) {
  std::shared_ptr<Player> player = std::make_shared<Player>();
  int32_t id = players.size();
  player -> SetId(id);

  if (name == std::string("Bot")) {
    player -> SetName(name + " " + std::to_string(id));
  } else {
    player -> SetName(name);
  }

  player -> generatePopulations();

  players.push_back(std::move(player));

  return id;
}

void GameEngine::setMaxStep(int32_t setMaxStep) {
  maxStep = setMaxStep;
}

void GameEngine::nextStep() {
  if (currentPlayer == botID) {
    botTurn(players[currentPlayer]);
    finishStep();
  }
}

void GameEngine::finishStep() {
  bool end = calculate();
  notify(end);

  if (!end) {
    ++currentStep;
    ++currentPlayer;
    currentPlayer %= players.size();
    nextStep();
  }
}

bool GameEngine::calculate() {
  calculateCells();
  applyLifeCycles();
  return !validate();
}

void GameEngine::calculateCells() {
  for (auto &row : *map) {
    for (auto &cell : row) {
      cell -> setHerbivoreCount(0);
      cell -> setCarnivoreCount(0);
    }
  }

  for (const auto & player : players) {
    for (const auto & population : player -> GetPlayerPopulations()) {
      int32_t xPos = population -> GetXPos();
      int32_t yPos = population -> GetYPos();

      int32_t herbivore = 0, carnivore = 0;

      if (population -> GetType() == Population::TypeName::CARNIVORE) {
        carnivore += population -> GetAnimalAmount();
      } else {
        herbivore += population -> GetAnimalAmount();
      }

      calculateCell(xPos, yPos, carnivore, herbivore);
      calculateCell(xPos + 1, yPos, carnivore, herbivore);
      calculateCell(xPos - 1, yPos, carnivore, herbivore);
      calculateCell(xPos, yPos + 1, carnivore, herbivore);
      calculateCell(xPos, yPos - 1, carnivore, herbivore);
    }
  }
}

void GameEngine::calculateCell(size_t posX, size_t posY, int32_t carnivore, int32_t herbivore) {
  auto cell = getCell(posX, posY);

  if (cell) {
    cell -> setCarnivoreCount(cell -> getCarnivoreCount() + carnivore);
    cell -> setHerbivoreCount(cell -> getHerbivoreCount() + herbivore);
  }
}

void GameEngine::applyLifeCycles() {
  for (auto & player : players) {
    for (auto &population : player -> GetPlayerPopulations()) {
      population -> SetAvailableStep(1);
      map -> applyLifeCircle(population);
    }
  }
}

/* It's really ineffective function */
bool GameEngine::validate() {
  std::vector<std::shared_ptr<Player> > newPlayers;
  for (const auto & player : players) {
    std::vector<std::shared_ptr<Population> > newPopulations;
    for (const auto &population : player -> GetPlayerPopulations()) {
      if (population -> GetAnimalAmount() > 0) {
        newPopulations.push_back(population);
      }
    }
    player -> SetPlayerPopulations(newPopulations);

    if (!newPopulations.empty()) {
      newPlayers.push_back(player);
    }
  }
  players = newPlayers;

  if ((players.size() < 2) || (currentStep > maxStep)) {
    std::cout << "End game!" << std::endl;
    return false;
  }
  return true;
}

void GameEngine::notify(bool end) {
  manager -> notifyDataChanged(end);
}

std::shared_ptr<Manager> GameEngine::getManager() {
  return manager;
}

void GameEngine::setManager(std::shared_ptr<Manager> setManager) {
  manager = std::move(setManager);
}

std::pair<int32_t, int32_t> GameEngine::getDestinationPos(std::shared_ptr<Population> tempPopulation) {
  int32_t xPos = tempPopulation->GetXPos();
  int32_t yPos = tempPopulation->GetYPos();
  int32_t dX = RandomGenerator::getInstance().randInt(-1, 1);
  int32_t dY = RandomGenerator::getInstance().randInt(-1, 1);
  if (yPos + dY < 0) {
    dY = RandomGenerator::getInstance().randInt(0, 1);
  }
  if (yPos + 1 >= map->getHeight()) {
    dY = RandomGenerator::getInstance().randInt(-1, 0);
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
  return std::make_pair(dX, dY);
}
