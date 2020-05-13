#include <vector>
#include "Player.h"

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


