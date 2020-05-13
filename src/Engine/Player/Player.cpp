#include <vector>

#include "Player.h"
#include "PopulationDirector.h"
#include "PopulationBuilder.h"

std::shared_ptr<Population> Player::getPopulation(int32_t number) {
  return playerPopulations[number];
}

void Player::addNewPopulation(std::shared_ptr<Population> new_population) {
  playerPopulations.push_back(std::move(new_population));
}

const std::vector<std::shared_ptr<Population>> &Player::GetPlayerPopulations() const {
  return playerPopulations;
}

void Player::SetPlayerPopulations(const std::vector<std::shared_ptr<Population>> &player_populations) {
  playerPopulations = player_populations;
}

const std::string &Player::GetName() const {
  return name;
}

void Player::SetName(const std::string &name) {
  Player::name = name;
}

void Player::generatePopulations() {
  PopulationDirector director;

  std::shared_ptr<PopulationBuilder> herbivoreBuilder = std::make_shared<HerbivorePopulationBuilder>();
  std::shared_ptr<PopulationBuilder> carnivoreBuilder = std::make_shared<CarnivorePopulationBuilder>();

  auto herbivoreNames = Config::getInstance().getHerbivoreNames();
  auto carnivoreNames = Config::getInstance().getCarnivoreNames();

  std::string herbivoreName = herbivoreNames[RandomGenerator::getInstance()
                                             .randInt(0, herbivoreNames.size() - 1)];
  std::string carnivoreName = carnivoreNames[RandomGenerator::getInstance()
                                             .randInt(0, carnivoreNames.size() - 1)];

  director.setBuilder(herbivoreBuilder);

  int32_t herbivoreType = RandomGenerator::getInstance().randInt(0, 2);
  int32_t carnivoreType = RandomGenerator::getInstance().randInt(0, 2);

  switch (herbivoreType) {
    case 0:
      playerPopulations.push_back(director.makeSmall(herbivoreName));
      break;
    case 1:
      playerPopulations.push_back(director.makeAverage(herbivoreName));
      break;
    case 2:
      playerPopulations.push_back(director.makeBig(herbivoreName));
      break;
  }

  director.setBuilder(carnivoreBuilder);

  switch (carnivoreType) {
    case 0:
      playerPopulations.push_back(director.makeSmall(carnivoreName));
      break;
    case 1:
      playerPopulations.push_back(director.makeAverage(carnivoreName));
      break;
    case 2:
      playerPopulations.push_back(director.makeBig(carnivoreName));
      break;
  }
}
