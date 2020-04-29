#include "CellTypeDirector.h"

void CellTypeDirector::setBuilder(AbstractCellTypeBuilder *builderPtr) {
  this -> builderPtr = builderPtr;
}

void CellTypeDirector::makeWaterCell() {
  builderPtr -> setType(CellType::cellType::WATER);
  builderPtr -> setClimate(CellType::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getWaterWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getWaterPlantsCount()));
}

void CellTypeDirector::makeForestCell() {
  builderPtr -> setType(CellType::cellType::FOREST);
  builderPtr -> setClimate(CellType::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getForestWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getForestPlantsCount()));
}

void CellTypeDirector::makeSteppeCell() {
  builderPtr -> setType(CellType::cellType::STEPPE);
  builderPtr -> setClimate(CellType::climateType::HOT);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getSteppeWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getSteppePlantsCount()));
}

void CellTypeDirector::makeTundraCell() {
  builderPtr -> setType(CellType::cellType::TUNDRA);
  builderPtr -> setClimate(CellType::climateType::COLD);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getTundraWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getTundraPlantsCount()));
}