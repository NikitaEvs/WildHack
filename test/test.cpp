#include "Map/CellTypeDirector.h"
#include "Map/CellTypeBuilder.h"
#include "Map/CellTypeJSONRepresentationBuilder.h"
#include "Map/Map.h"
#include "PopulationDirector.h"

#include "Engine/GameEngine.h"

#include <iostream>
#include <string>

void generateSimpleMap() {
  Map map(3, 3);
  CellTypeDirector director;
  std::shared_ptr<CellTypeBuilder> builder = std::make_shared<CellTypeBuilder>();
  director.setBuilder(builder.get());

  for (auto &row : map) {
    for (auto &cell : row) {
      director.makeForestCell();
      cell = builder -> getProduct();
    }
  }

  std::stringstream stream;
  map.saveTo(stream);

  Map copy;
  copy.loadFrom(stream);

  std::cout << *(copy[0][0]) << std::endl;
}

int main() {
  auto builder = new CellTypeBuilder();
  auto jsonBuilder = new CellTypeJSONRepresentationBuilder();

  CellTypeDirector director;
  director.setBuilder(builder);
  director.makeSteppeCell();
  std::shared_ptr<CellType> steppeCell = builder -> getProduct();
  std::cout << *steppeCell << std::endl;

  director.setBuilder(jsonBuilder);
  director.makeWaterCell();
  auto waterCell = jsonBuilder -> getProduct();
  std::cout << waterCell << std::endl;

  delete builder;
  delete jsonBuilder;

  PopulationDirector d;
  std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
  d.setBuilder(b);
  std::shared_ptr<Population> p = d.makeBig("elephant");
  std::cout << *p;

  generateSimpleMap();

  p->addMutation();
  p->applyMutation();
  std::cout << *p;
  p->addMutation();
  p->applyMutation();
  std::cout << *p;

  return 0;
}
