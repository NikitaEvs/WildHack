#include "Map/CellTypeDirector.h"
#include "Map/CellTypeBuilder.h"
#include "Map/CellTypeJSONRepresentationBuilder.h"
#include "Map/Map.h"
#include "PopulationDirector.h"

#include <iostream>
#include <string>

int main() {
  std::cout << "***Create cell example code***" << std:: endl;

  CellTypeDirector director;

  auto builder = new CellTypeBuilder();
  director.setBuilder(builder);
  director.makeSteppeCell();
  std::shared_ptr<CellType> steppeCell = builder -> getProduct();
  std::cout << *steppeCell << std::endl;

  auto jsonBuilder = new CellTypeJSONRepresentationBuilder();
  director.setBuilder(jsonBuilder);
  director.makeWaterCell();
  auto waterCell = jsonBuilder -> getProduct();
  std::cout << waterCell << std::endl;

  delete builder;
  delete jsonBuilder;


  std::cout << "***Create population example code***" << std:: endl;
  PopulationDirector d;
  std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
  d.setBuilder(b);
  std::shared_ptr<Population> p = d.makeBig("elephant");
  std::cout << *p;

  std::cout << "***Mutation example code***" << std::endl;
  p->addMutation();
  p->applyMutation();
  std::cout << *p;
  p->addMutation();
  p->applyMutation();
  std::cout << *p;

  std::cout << "***Generate map example code***" << std::endl;
  Map map(10, 10);
  map.generate();
  for (int kI = 0; kI < 10; ++kI) {
    for (int kJ = 0; kJ < 10; ++kJ) {
      std::cout << map[kI][kJ]->type << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
