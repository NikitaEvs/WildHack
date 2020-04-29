#include "CellTypeJSONRepresentationBuilder.h"

void CellTypeJSONRepresentationBuilder::reset() {
  cellJson.clear();
}

void CellTypeJSONRepresentationBuilder::setType(CellType::cellType cellType) {
  cellJson["cellType"] = static_cast<int32_t>(cellType);
}

void CellTypeJSONRepresentationBuilder::setClimate(CellType::climateType climateType) {
  cellJson["climateType"] = static_cast<int32_t>(climateType);
}

void CellTypeJSONRepresentationBuilder::setPlantFood(int32_t plantsCount) {
  cellJson["plantsCount"] = plantsCount;
}

void CellTypeJSONRepresentationBuilder::setWaterLevel(int32_t waterLevel) {
  cellJson["waterLevel"] = waterLevel;
}

nlohmann::json CellTypeJSONRepresentationBuilder::getProduct() {
  reset();
  return cellJson;
}