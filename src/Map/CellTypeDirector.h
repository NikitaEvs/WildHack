#pragma once

#include <memory>

#include "Config.h"
#include "Random.h"
#include "AbstractCellTypeBuilder.h"
#include "CellType.h"

class CellTypeDirector {
 private:
  AbstractCellTypeBuilder *builderPtr;

 public:
  CellTypeDirector() = default;
  CellTypeDirector(AbstractCellTypeBuilder *builderPtr) : builderPtr(builderPtr){};
  void setBuilder(AbstractCellTypeBuilder *builderPtr);
  void makeWaterCell();
  void makeForestCell();
  void makeSteppeCell();
  void makeTundraCell();
};
