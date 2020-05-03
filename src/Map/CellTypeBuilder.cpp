#include "CellTypeBuilder.h"

CellTypeBuilder::CellTypeBuilder() {
  reset();
}

void CellTypeBuilder::reset() {
  cellPtr = std::make_shared<CellType>();
}

void CellTypeBuilder::setType(CellType::cellType cellType) {
  cellPtr -> type = cellType;
}

void CellTypeBuilder::setClimate(CellType::climateType climateType) {
  cellPtr -> climate = climateType;
}

void CellTypeBuilder::setPlantFood(int32_t plantsCount) {
  cellPtr -> plantsCount = plantsCount;
}

void CellTypeBuilder::setWaterLevel(int32_t waterLevel) {
  cellPtr -> waterLevel = waterLevel;
}

std::shared_ptr<CellType> CellTypeBuilder::getProduct() {
  std::shared_ptr<CellType> oldPtr = std::move(cellPtr);
  reset();
  return oldPtr;
}
