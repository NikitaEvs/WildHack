#include "Map/CellTypeDirector.h"
#include "Map/CellTypeBuilder.h"
#include "PopulationDirector.h"

#include <iostream>

int main() {
  auto builder = new CellTypeBuilder();
  CellTypeDirector director;
  director.setBuilder(builder);
  director.makeSteppeCell();
  std::shared_ptr<CellType> waterCell = builder->getProduct();
  std::cout << *waterCell << std::endl;
  delete builder;

  PopulationDirector d;
  std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
  d.setBuilder(b);
  std::shared_ptr<Population> p = d.makeBig("elephant");
  std::cout << *p;

  return 0;
}