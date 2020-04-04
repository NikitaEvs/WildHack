#ifndef PEACH_SRC_ANIMALS_POPULATIONDIRECTOR_H_
#define PEACH_SRC_ANIMALS_POPULATIONDIRECTOR_H_

#include "PopulationBuilder.h"

class PopulationDirector{
 private:
  std::shared_ptr<PopulationBuilder> builder;
 public:
  void setBuilder(std::shared_ptr<PopulationBuilder> b);
  Population makeSmall();
  Population makeAverage();
  Population makeBig();
};

#endif //PEACH_SRC_ANIMALS_POPULATIONDIRECTOR_H_
