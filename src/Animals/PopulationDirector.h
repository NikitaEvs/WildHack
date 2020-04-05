#ifndef PEACH_SRC_ANIMALS_POPULATIONDIRECTOR_H_
#define PEACH_SRC_ANIMALS_POPULATIONDIRECTOR_H_

#include <memory>

#include "Config.h"
#include "Random.h"
#include "PopulationBuilder.h"
#include "HerbivorePopulationBuilder.cpp"
#include "CarnivorePopulationBuilder.cpp"

class PopulationDirector{
 private:
  std::shared_ptr<PopulationBuilder> builder;
  std::shared_ptr<Random> randomPtr = Random::getInstance();
  std::shared_ptr<Config> configPtr = Config::getInstance();

 public:
  void setBuilder(std::shared_ptr<PopulationBuilder> b);
  std::shared_ptr<Population> makeSmall(std::string name);
  std::shared_ptr<Population> makeAverage(std::string name);
  std::shared_ptr<Population> makeBig(std::string name);
};

#endif //PEACH_SRC_ANIMALS_POPULATIONDIRECTOR_H_
