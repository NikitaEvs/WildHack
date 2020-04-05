#include "Map/CellDirector.h"
#include "Map/CellBuilder.h"
#include "PopulationDirector.h"

#include <iostream>

int main() {
  auto builder = new CellBuilder();
  CellDirector director;
  director.setBuilder(builder);
  director.makeSteppeCell();
  std::shared_ptr<Cell> waterCell = builder->getProduct();
  std::cout << *waterCell << std::endl;
  delete builder;

  PopulationDirector d;
  std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
  d.setBuilder(b);
  std::shared_ptr<Population> p = d.makeBig("elephant");
  std::cout << *p;

  return 0;
}