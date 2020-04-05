#ifndef SRC_CELLBUILDER_H_
#define SRC_CELLBUILDER_H_

#include <memory>
#include "Cell.h"
#include "AbstractCellBuilder.h"

class CellBuilder :  public AbstractCellBuilder {
 private:
  Cell *cellPtr;

 public:
  CellBuilder();
  void reset();
  void setType(Cell::cellType cellType) override;
  void setClimate(Cell::climateType climateType) override;
  void setPlantFood(int32_t plantsCount) override;
  void setWaterLevel(int32_t waterLevel) override;
  Cell *getProduct();
};

#endif //SRC_CELLBUILDER_H_
