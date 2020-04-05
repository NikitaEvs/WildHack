#include "Map/CellDirector.h"
#include "Map/CellBuilder.h"

#include <iostream>

int main() {
  auto builder = new CellBuilder();
  CellDirector director;
  director.setBuilder(builder);
  director.makeSteppeCell();
  std::shared_ptr<Cell> waterCell = builder->getProduct();
  std::cout << *waterCell << std::endl;
  delete builder;

  return 0;
}