#include <vector>

#include "Player.h"
#include "PopulationDirector.h"
#include "PopulationBuilder.h"

Player::Player(int32_t setID) : id(setID) {}

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

size_t Player::getPopulationsNumber() {
  return playerPopulations.size();
}

size_t Player::calculateScore() const {
  size_t score = 0;

  for (const auto & population : playerPopulations) {
    score += population -> GetBiologyDev();
  }

  return score;
}

int32_t Player::GetId() const {
  return id;
}

void Player::SetId(int32_t id) {
  Player::id = id;
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

  if (!playerPopulations.empty()) {
    playerPopulations[0] -> SetPlayerNumber(id);
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

  if (playerPopulations.size() > 1) {
    playerPopulations[1] -> SetPlayerNumber(id);
  }
}

LightPlayer::LightPlayer(const Player &player) {
  score = player.calculateScore();
  name = player.GetName();
}

const std::string &LightPlayer::getName() const {
  return name;
}

void LightPlayer::setName(const std::string &setName) {
  name = setName;
}

size_t LightPlayer::getScore() const {
  return score;
}

void LightPlayer::setScore(size_t setScore) {
  score = setScore;
}
