#pragma once

#include "CellType.h"

class AbstractCellTypeBuilder {
 public:
  AbstractCellTypeBuilder() = default;
  virtual ~AbstractCellTypeBuilder()= default;

  virtual void setType(CellType::cellType cellType) = 0;
  virtual void setClimate(CellType::climateType climateType) = 0;
  virtual void setPlantFood(int32_t plantsCount) = 0;
  virtual void setWaterLevel(int32_t waterLevel) = 0;
};
