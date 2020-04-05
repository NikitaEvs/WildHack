#include "CellJSONRepresentationBuilder.h"

void CellJSONRepresentationBuilder::reset() {
  cellJson.clear();
}

void CellJSONRepresentationBuilder::setType(Cell::cellType cellType) {
  cellJson["cellType"] = static_cast<int32_t>(cellType);
}

void CellJSONRepresentationBuilder::setClimate(Cell::climateType climateType) {
  cellJson["climateType"] = static_cast<int32_t>(climateType);
}

void CellJSONRepresentationBuilder::setPlantFood(int32_t plantsCount) {
  cellJson["plantsCount"] = plantsCount;
}

void CellJSONRepresentationBuilder::setWaterLevel(int32_t waterLevel) {
  cellJson["waterLevel"] = waterLevel;
}

nlohmann::json CellJSONRepresentationBuilder::getProduct() {
  reset();
  return cellJson;
}