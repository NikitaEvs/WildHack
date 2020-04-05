#include "CellBuilder.h"

CellBuilder::CellBuilder() {
  reset();
}

void CellBuilder::reset() {
  cellPtr = new Cell();
}

void CellBuilder::setType(Cell::cellType cellType) {
  cellPtr -> type = cellType;
}

void CellBuilder::setClimate(Cell::climateType climateType) {
  cellPtr -> climate = climateType;
}

void CellBuilder::setPlantFood(int32_t plantsCount) {
  cellPtr -> plantsCount = plantsCount;
}

void CellBuilder::setWaterLevel(int32_t waterLevel) {
  cellPtr -> waterLevel = waterLevel;
}

Cell* CellBuilder::getProduct() {
  Cell *oldPtr = cellPtr;
  reset();
  return oldPtr;
}
