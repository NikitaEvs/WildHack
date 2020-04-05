#include "PopulationDirector.h"

void PopulationDirector::setBuilder(std::shared_ptr<PopulationBuilder> b) {
  builder = b;
}
std::shared_ptr<Population> PopulationDirector::makeSmall(std::string name) {
  builder->setName(name);
  builder->setType();
  if (builder->getProduct()->type == "herbivore") {
    builder->setAmount(randomPtr->randNormalInt(configPtr->getHerbivoreSmallAnimalAmount()));
    builder->setHealth(randomPtr->randNormalInt(configPtr->getHerbivoreSmallHealth()));
    builder->setProductivity(randomPtr->randNormalInt(configPtr->getHerbivoreSmallProductivity()));
    builder->setWellBeing(randomPtr->randNormalInt(configPtr->getHerbivoreSmallWellBeing()));
    builder->setBiologyDev(randomPtr->randNormalInt(configPtr->getHerbivoreSmallBiologyDev()));
    builder->setSize(Population::SMALL);
    builder->setSafety(Population::AVERAGE);
    builder->setVelocity(Population::SMALL);
    builder->setCover(Population::AVERAGE);
  } else {
    builder->setAmount(randomPtr->randNormalInt(configPtr->getCarnivoreSmallAnimalAmount()));
    builder->setHealth(randomPtr->randNormalInt(configPtr->getCarnivoreSmallHealth()));
    builder->setProductivity(randomPtr->randNormalInt(configPtr->getCarnivoreSmallProductivity()));
    builder->setWellBeing(randomPtr->randNormalInt(configPtr->getCarnivoreSmallWellBeing()));
    builder->setBiologyDev(randomPtr->randNormalInt(configPtr->getCarnivoreSmallBiologyDev()));
    builder->setSize(Population::SMALL);
    builder->setSafety(Population::AVERAGE);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::SMALL);
  }

  return builder->getProduct();
}
std::shared_ptr<Population> PopulationDirector::makeAverage(std::string name) {
  builder->setName(name);
  builder->setType();
  if (builder->getProduct()->type == "herbivore") {
    builder->setAmount(randomPtr->randNormalInt(configPtr->getHerbivoreAverageAnimalAmount()));
    builder->setHealth(randomPtr->randNormalInt(configPtr->getHerbivoreAverageHealth()));
    builder->setProductivity(randomPtr->randNormalInt(configPtr->getHerbivoreAverageProductivity()));
    builder->setWellBeing(randomPtr->randNormalInt(configPtr->getHerbivoreAverageWellBeing()));
    builder->setBiologyDev(randomPtr->randNormalInt(configPtr->getHerbivoreAverageBiologyDev()));
    builder->setSize(Population::AVERAGE);
    builder->setSafety(Population::AVERAGE);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::AVERAGE);
  } else {
    builder->setAmount(randomPtr->randNormalInt(configPtr->getCarnivoreAverageAnimalAmount()));
    builder->setHealth(randomPtr->randNormalInt(configPtr->getCarnivoreAverageHealth()));
    builder->setProductivity(randomPtr->randNormalInt(configPtr->getCarnivoreAverageProductivity()));
    builder->setWellBeing(randomPtr->randNormalInt(configPtr->getCarnivoreAverageWellBeing()));
    builder->setBiologyDev(randomPtr->randNormalInt(configPtr->getCarnivoreAverageBiologyDev()));
    builder->setSize(Population::AVERAGE);
    builder->setSafety(Population::AVERAGE);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::AVERAGE);
  }
  return builder->getProduct();
}

std::shared_ptr<Population> PopulationDirector::makeBig(std::string name) {
  builder->setName(name);
  builder->setType();
  if (builder->getProduct()->type == "herbivore") {
    builder->setAmount(randomPtr->randNormalInt(configPtr->getHerbivoreBigAnimalAmount()));
    builder->setHealth(randomPtr->randNormalInt(configPtr->getHerbivoreBigHealth()));
    builder->setProductivity(randomPtr->randNormalInt(configPtr->getHerbivoreBigProductivity()));
    builder->setWellBeing(randomPtr->randNormalInt(configPtr->getHerbivoreBigWellBeing()));
    builder->setBiologyDev(randomPtr->randNormalInt(configPtr->getHerbivoreBigBiologyDev()));
    builder->setSize(Population::BIG);
    builder->setSafety(Population::BIG);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::BIG);
  } else {
    builder->setAmount(randomPtr->randNormalInt(configPtr->getCarnivoreBigAnimalAmount()));
    builder->setHealth(randomPtr->randNormalInt(configPtr->getCarnivoreBigHealth()));
    builder->setProductivity(randomPtr->randNormalInt(configPtr->getCarnivoreBigProductivity()));
    builder->setWellBeing(randomPtr->randNormalInt(configPtr->getCarnivoreBigWellBeing()));
    builder->setBiologyDev(randomPtr->randNormalInt(configPtr->getCarnivoreBigBiologyDev()));
    builder->setSize(Population::BIG);
    builder->setSafety(Population::BIG);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::AVERAGE);
  }

  return builder->getProduct();
}