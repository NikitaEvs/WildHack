#include "CellTypeDirector.h"

void CellTypeDirector::setBuilder(std::shared_ptr<AbstractCellTypeBuilder> newBuilder) {
  builderPtr = std::move(newBuilder);
}

void CellTypeDirector::makeWaterCell() {
  builderPtr -> setType(CellType::cellType::WATER);
  builderPtr -> setClimate(CellType::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getWaterWaterLevel()));
  builderPtr -> setPlantFood(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getWaterPlantsCount()));
}

void CellTypeDirector::makeForestCell() {
  builderPtr -> setType(CellType::cellType::FOREST);
  builderPtr -> setClimate(CellType::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getForestWaterLevel()));
  builderPtr -> setPlantFood(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getForestPlantsCount()));
}

void CellTypeDirector::makeSteppeCell() {
  builderPtr -> setType(CellType::cellType::STEPPE);
  builderPtr -> setClimate(CellType::climateType::HOT);
  builderPtr -> setWaterLevel(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getSteppeWaterLevel()));
  builderPtr -> setPlantFood(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getSteppePlantsCount()));
}

void CellTypeDirector::makeTundraCell() {
  builderPtr -> setType(CellType::cellType::TUNDRA);
  builderPtr -> setClimate(CellType::climateType::COLD);
  builderPtr -> setWaterLevel(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getTundraWaterLevel()));
  builderPtr -> setPlantFood(RandomGenerator::getInstance().randNormalInt(Config::getInstance().getTundraPlantsCount()));
}