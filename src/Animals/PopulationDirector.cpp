#include "PopulationDirector.h"

void PopulationDirector::setBuilder(std::shared_ptr<PopulationBuilder> b) {
  builder = b;
}

std::shared_ptr<Population> PopulationDirector::makeSmall(std::string name) {
  builder->setName(name);
  builder->setType();
  if (builder->getProduct()->GetType() == Population::TypeName::HERBIVORE) {
    builder->setAmount(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreSmallAnimalAmount()));
    builder->setHealth(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreSmallHealth()));
    builder->setProductivity(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreSmallProductivity()));
    builder->setBiologyDev(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreSmallBiologyDev()));
    builder->setSize(Population::SMALL);
    builder->setSafety(Population::AVERAGE);
    builder->setVelocity(Population::SMALL);
    builder->setCover(Population::AVERAGE);
  } else {
    builder->setAmount(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreSmallAnimalAmount()));
    builder->setHealth(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreSmallHealth()));
    builder->setProductivity(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreSmallProductivity()));
    builder->setBiologyDev(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreSmallBiologyDev()));
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
  if (builder->getProduct()->GetType() == Population::TypeName::HERBIVORE) {
    builder->setAmount(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreAverageAnimalAmount()));
    builder->setHealth(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreAverageHealth()));
    builder->setProductivity(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreAverageProductivity()));
    builder->setBiologyDev(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreAverageBiologyDev()));
    builder->setSize(Population::AVERAGE);
    builder->setSafety(Population::AVERAGE);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::AVERAGE);
  } else {
    builder->setAmount(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreAverageAnimalAmount()));
    builder->setHealth(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreAverageHealth()));
    builder->setProductivity(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreAverageProductivity()));
    builder->setBiologyDev(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreAverageBiologyDev()));
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
  if (builder->getProduct()->GetType() == Population::TypeName::HERBIVORE) {
    builder->setAmount(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreBigAnimalAmount()));
    builder->setHealth(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreBigHealth()));
    builder->setProductivity(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreBigProductivity()));
    builder->setBiologyDev(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHerbivoreBigBiologyDev()));
    builder->setSize(Population::BIG);
    builder->setSafety(Population::BIG);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::BIG);
  } else {
    builder->setAmount(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreBigAnimalAmount()));
    builder->setHealth(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreBigHealth()));
    builder->setProductivity(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreBigProductivity()));
    builder->setBiologyDev(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getCarnivoreBigBiologyDev()));
    builder->setSize(Population::BIG);
    builder->setSafety(Population::BIG);
    builder->setVelocity(Population::AVERAGE);
    builder->setCover(Population::AVERAGE);
  }
  return builder->getProduct();
}