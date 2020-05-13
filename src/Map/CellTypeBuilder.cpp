#include "CellTypeBuilder.h"

CellTypeBuilder::CellTypeBuilder() {
  reset();
}

void CellTypeBuilder::reset() {
  cellPtr = std::make_shared<CellType>();
}

void CellTypeBuilder::setType(CellType::cellType cellType) {
  cellPtr -> setType(cellType);
}

void CellTypeBuilder::setClimate(CellType::climateType climateType) {
  cellPtr -> setClimate(climateType);
}

void CellTypeBuilder::setPlantFood(int32_t plantsCount) {
  cellPtr -> setPlantsCount(plantsCount);
}

void CellTypeBuilder::setWaterLevel(int32_t waterLevel) {
  cellPtr -> setWaterLevel(waterLevel);
}

std::shared_ptr<CellType> CellTypeBuilder::getProduct() {
  std::shared_ptr<CellType> oldPtr = std::move(cellPtr);
  reset();
  return oldPtr;
}
