#pragma once

#include <memory>
#include "CellType.h"
#include "AbstractCellTypeBuilder.h"

class CellTypeBuilder : public AbstractCellTypeBuilder {
 private:
  CellType *cellPtr;

 public:
  CellTypeBuilder();
  ~CellTypeBuilder();

  void reset();

  void setType(CellType::cellType cellType) override;
  void setClimate(CellType::climateType climateType) override;
  void setPlantFood(int32_t plantsCount) override;
  void setWaterLevel(int32_t waterLevel) override;

  std::shared_ptr<CellType> getProduct();
};
