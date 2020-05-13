#pragma once

#include <memory>

#include "Config.h"
#include "RandomGenerator.h"
#include "PopulationBuilder.h"
#include "HerbivorePopulationBuilder.cpp"
#include "CarnivorePopulationBuilder.cpp"

class PopulationDirector{
 private:
  std::shared_ptr<PopulationBuilder> builder;

 public:
  void setBuilder(std::shared_ptr<PopulationBuilder> b);

  std::shared_ptr<Population> makeSmall(const std::string &name);
  std::shared_ptr<Population> makeAverage(const std::string &name);
  std::shared_ptr<Population> makeBig(const std::string &name);
};
