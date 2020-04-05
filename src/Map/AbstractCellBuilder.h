#ifndef SRC_ABSTRACTCELLBUILDER_H_
#define SRC_ABSTRACTCELLBUILDER_H_

#include "Cell.h"

class AbstractCellBuilder {
 public:
  virtual ~AbstractCellBuilder(){}
  virtual void setType(Cell::cellType cellType) = 0;
  virtual void setClimate(Cell::climateType climateType) = 0;
  virtual void setPlantFood(int32_t plantsCount) = 0;
  virtual void setWaterLevel(int32_t waterLevel) = 0;
};

#endif //SRC_ABSTRACTCELLBUILDER_H_