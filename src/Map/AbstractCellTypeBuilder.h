#ifndef SRC_ABSTRACTCELLBUILDER_H_
#define SRC_ABSTRACTCELLBUILDER_H_

#include "CellType.h"

class AbstractCellTypeBuilder {
 public:
  virtual ~AbstractCellTypeBuilder(){}
  virtual void setType(CellType::cellType cellType) = 0;
  virtual void setClimate(CellType::climateType climateType) = 0;
  virtual void setPlantFood(int32_t plantsCount) = 0;
  virtual void setWaterLevel(int32_t waterLevel) = 0;
};

#endif //SRC_ABSTRACTCELLBUILDER_H_