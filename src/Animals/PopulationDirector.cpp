#include "PopulationDirector.h"

void PopulationDirector::setBuilder(std::shared_ptr<PopulationBuilder> b) {
  builder = b;
}
Population PopulationDirector::makeSmall() {
  builder.setType();
  builder.setAmount(500);
  builder.setHealth(60);
  builder.setProductivity(8);
  builder.setWellBeing(50);
  builder.setBiologyDev(20);
  builder.setSize(Population::SMALL);
  builder.setSafety(Population::AVERAGE);
  builder.setVelocity(Population::SMALL);
  builder.setCover(Population::SMALL);
}
Population PopulationDirector::makeAverage() {
  builder.setType();
  builder.setAmount(200);
  builder.setHealth(70);
  builder.setProductivity(4);
  builder.setWellBeing(50);
  builder.setBiologyDev(20);
  builder.setSize(Population::AVERAGE);
  builder.setSafety(Population::AVERAGE);
  builder.setVelocity(Population::AVERAGE);
  builder.setCover(Population::AVERAGE);
}
Population PopulationDirector::makeBig() {
  builder.setType();
  builder.setAmount(50);
  builder.setHealth(80);
  builder.setProductivity(1);
  builder.setWellBeing(60);
  builder.setBiologyDev(20);
  builder.setSize(Population::BIG);
  builder.setSafety(Population::BIG);
  builder.setVelocity(Population::AVERAGE);
  builder.setCover(Population::AVERAGE);
}