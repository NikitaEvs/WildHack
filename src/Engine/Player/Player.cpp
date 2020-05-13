#include <vector>
#include "Player.h"

std::shared_ptr<Population> Player::getPopulation(int number) {
  return playerPopulations[number];
}

void Player::addNewPopulation(std::shared_ptr<Population> new_population) {
  playerPopulations.push_back(new_population);
}


const std::vector<std::shared_ptr<Population>> &Player::GetPlayerPopulations() const {
  return playerPopulations;
}
void Player::SetPlayerPopulations(const std::vector<std::shared_ptr<Population>> &player_populations) {
  playerPopulations = player_populations;
}
const std::__cxx11::basic_string<char> &Player::GetName() const {
  return name;
}
void Player::SetName(const std::__cxx11::basic_string<char> &name) {
  Player::name = name;
}
