#ifndef SRC_CELLJSONREPRESENTATIONBUILDER_H_
#define SRC_CELLJSONREPRESENTATIONBUILDER_H_

#include "json/json.hpp"

#include "CellType.h"
#include "AbstractCellTypeBuilder.h"

class CellTypeJSONRepresentationBuilder : AbstractCellTypeBuilder {
 private:
  nlohmann::json cellJson;

 public:
  void reset();
  void setType(CellType::cellType cellType) override;
  void setClimate(CellType::climateType climateType) override;
  void setPlantFood(int32_t plantsCount) override;
  void setWaterLevel(int32_t waterLevel) override;
  nlohmann::json getProduct();
};


#endif //SRC_CELLJSONREPRESENTATIONBUILDER_H_
