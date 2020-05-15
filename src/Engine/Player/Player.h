#pragma once

#include <vector>
#include <memory>
#include <string>

#include "PopulationDirector.h"

class Player {
 public:
  explicit Player(int32_t setID);

  Player() = default;

  std::shared_ptr<Population> getPopulation(int32_t number);
  void addNewPopulation(std::shared_ptr<Population> new_population);

  const std::vector<std::shared_ptr<Population>> &GetPlayerPopulations() const;
  void SetPlayerPopulations(const std::vector<std::shared_ptr<Population>> &player_populations);

  int32_t GetId() const;
  void SetId(int32_t id);

  const std::string &GetName() const;
  void SetName(const std::string &name);

  void generatePopulations();

  size_t getPopulationsNumber();

  size_t calculateScore() const;
 private:
  std::vector<std::shared_ptr<Population> > playerPopulations;

  std::string name;

  int32_t id;
};

class LightPlayer {
 public:
  LightPlayer(const Player& player);

  const std::string &getName() const;
  void setName(const std::string &name);
  size_t getScore() const;
  void setScore(size_t score);
 private:
  std::string name;
  size_t score = 0;
};
