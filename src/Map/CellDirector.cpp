#include "CellDirector.h"

void CellDirector::setBuilder(AbstractCellBuilder *builderPtr) {
  this -> builderPtr = builderPtr;
}

void CellDirector::makeWaterCell() {
  builderPtr -> setType(Cell::cellType::WATER);
  builderPtr -> setClimate(Cell::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getWaterWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getWaterPlantsCount()));
}

void CellDirector::makeForestCell() {
  builderPtr -> setType(Cell::cellType::FOREST);
  builderPtr -> setClimate(Cell::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getForestWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getForestPlantsCount()));
}

void CellDirector::makeSteppeCell() {
  builderPtr -> setType(Cell::cellType::STEPPE);
  builderPtr -> setClimate(Cell::climateType::HOT);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getSteppeWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getSteppePlantsCount()));
}

void CellDirector::makeTundraCell() {
  builderPtr -> setType(Cell::cellType::TUNDRA);
  builderPtr -> setClimate(Cell::climateType::COLD);
  builderPtr -> setWaterLevel(Random::getInstance().randNormalInt(Config::getInstance().getTundraWaterLevel()));
  builderPtr -> setPlantFood(Random::getInstance().randNormalInt(Config::getInstance().getTundraPlantsCount()));
}