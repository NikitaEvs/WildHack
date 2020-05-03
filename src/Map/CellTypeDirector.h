#pragma once

#include <memory>
#include <utility>

#include "Config.h"
#include "RandomGenerator.h"
#include "AbstractCellTypeBuilder.h"
#include "CellType.h"

class CellTypeDirector {
 public:
  CellTypeDirector() = default;
  CellTypeDirector(std::shared_ptr<AbstractCellTypeBuilder> builderPtr) : builderPtr(std::move(builderPtr)){};

  void setBuilder(std::shared_ptr<AbstractCellTypeBuilder> builderPtr);

  void makeWaterCell();
  void makeForestCell();
  void makeSteppeCell();
  void makeTundraCell();

 private:
  std::shared_ptr<AbstractCellTypeBuilder> builderPtr;
};
