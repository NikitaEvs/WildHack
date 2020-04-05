#ifndef SRC_MAP_CELLDIRECTOR_H_
#define SRC_MAP_CELLDIRECTOR_H_

#include <memory>

#include "Config.h"
#include "Random.h"
#include "AbstractCellBuilder.h"
#include "Cell.h"

class CellDirector {
 private:
  AbstractCellBuilder *builderPtr;

 public:
  CellDirector() = default;
  CellDirector(AbstractCellBuilder *builderPtr) : builderPtr(builderPtr){};
  void setBuilder(AbstractCellBuilder *builderPtr);
  void makeWaterCell();
  void makeForestCell();
  void makeSteppeCell();
  void makeTundraCell();
};

#endif //SRC_MAP_CELLDIRECTOR_H_
