#pragma once

#include <vector>
#include <memory>

#include "PopulationDirector.h"

class Player {
 public:
  std::shared_ptr<Population> getPopulation(int number);
  void addNewPopulation(std::shared_ptr<Population> new_population);
  const std::vector<std::shared_ptr<Population>> &GetPlayerPopulations() const;
  void SetPlayerPopulations(const std::vector<std::shared_ptr<Population>> &player_populations);
  const std::string &GetName() const;
  void SetName(const std::string &name);
 private:
  std::vector<std::shared_ptr<Population> > playerPopulations;
  std::string name;
};