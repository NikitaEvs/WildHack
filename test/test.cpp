#include "Map/CellDirector.h"
#include "Map/CellBuilder.h"

#include <iostream>

int main() {
  auto builder = new CellBuilder();
  CellDirector director;
  director.setBuilder(builder);
  director.makeSteppeCell();
  Cell* waterCell = builder->getProduct();
  std::cout << *waterCell << std::endl;

  return 0;
}