#pragma once

#include "json/json.hpp"

#include "CellType.h"
#include "AbstractCellTypeBuilder.h"

class CellTypeJSONRepresentationBuilder : public AbstractCellTypeBuilder {
 public:
  void reset();

  void setType(CellType::cellType cellType) override;
  void setClimate(CellType::climateType climateType) override;
  void setPlantFood(int32_t plantsCount) override;
  void setWaterLevel(int32_t waterLevel) override;

  nlohmann::json getProduct();

 private:
  nlohmann::json cellJson;
};
