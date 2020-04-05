#include "CellDirector.h"

void CellDirector::setBuilder(AbstractCellBuilder *builderPtr) {
  this -> builderPtr = builderPtr;
}

void CellDirector::makeWaterCell() {
  builderPtr -> setType(Cell::cellType::WATER);
  builderPtr -> setClimate(Cell::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(randomPtr -> randNormalInt(configPtr -> getWaterWaterLevel()));
  builderPtr -> setPlantFood(randomPtr -> randNormalInt(configPtr -> getWaterPlantsCount()));
}

void CellDirector::makeForestCell() {
  builderPtr -> setType(Cell::cellType::FOREST);
  builderPtr -> setClimate(Cell::climateType::TEMPERATE);
  builderPtr -> setWaterLevel(randomPtr -> randNormalInt(configPtr -> getForestWaterLevel()));
  builderPtr -> setPlantFood(randomPtr -> randNormalInt(configPtr -> getForestPlantsCount()));
}

void CellDirector::makeSteppeCell() {
  builderPtr -> setType(Cell::cellType::STEPPE);
  builderPtr -> setClimate(Cell::climateType::HOT);
  builderPtr -> setWaterLevel(randomPtr -> randNormalInt(configPtr -> getSteppeWaterLevel()));
  builderPtr -> setPlantFood(randomPtr -> randNormalInt(configPtr -> getSteppePlantsCount()));
}

void CellDirector::makeTundraCell() {
  builderPtr -> setType(Cell::cellType::TUNDRA);
  builderPtr -> setClimate(Cell::climateType::COLD);
  builderPtr -> setWaterLevel(randomPtr -> randNormalInt(configPtr -> getTundraWaterLevel()));
  builderPtr -> setPlantFood(randomPtr -> randNormalInt(configPtr -> getTundraPlantsCount()));
}