#ifndef SRC_CELLJSONREPRESENTATIONBUILDER_H_
#define SRC_CELLJSONREPRESENTATIONBUILDER_H_

#include "json/json.hpp"

#include "Cell.h"
#include "AbstractCellBuilder.h"

class CellJSONRepresentationBuilder : AbstractCellBuilder {
 private:
  nlohmann::json cellJson;

 public:
  void reset();
  void setType(Cell::cellType cellType) override;
  void setClimate(Cell::climateType climateType) override;
  void setPlantFood(int32_t plantsCount) override;
  void setWaterLevel(int32_t waterLevel) override;
  nlohmann::json getProduct();
};


#endif //SRC_CELLJSONREPRESENTATIONBUILDER_H_
