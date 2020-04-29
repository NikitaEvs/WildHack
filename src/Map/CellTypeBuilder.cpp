#include "CellTypeBuilder.h"

CellTypeBuilder::CellTypeBuilder() {
  reset();
}

CellTypeBuilder::~CellTypeBuilder() {
  delete cellPtr;
}

void CellTypeBuilder::reset() {
  cellPtr = new CellType();
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
  CellType *oldPtr = cellPtr;
  reset();
  return std::shared_ptr<CellType>(oldPtr);
}
