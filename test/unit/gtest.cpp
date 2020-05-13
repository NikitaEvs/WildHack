#include <gtest/gtest.h>

#include "Animals/PopulationDirector.h"
#include "Animals/PopulationBuilder.h"

#include "Map/CellTypeBuilder.h"
#include "Map/CellTypeDirector.h"
#include "Map/CellTypeJSONRepresentationBuilder.h"
#include "Map/Map.h"

#include "Engine/GameEngine.h"


TEST(Unit, CreateCell) {
  CellTypeDirector director;

  auto builder = std::make_shared<CellTypeBuilder>();
  director.setBuilder(builder);
  director.makeWaterCell();
  std::shared_ptr<CellType> waterCell = builder -> getProduct();

  ASSERT_EQ(waterCell -> getWaterLevel(), 100);
}

TEST(Unit, CreateCellJSON) {
  CellTypeDirector director;

  auto builder = std::make_shared<CellTypeJSONRepresentationBuilder>();
  director.setBuilder(builder);
  director.makeWaterCell();
  auto waterCell = builder -> getProduct();

  ASSERT_EQ(waterCell["waterLevel"], 100);
}

TEST(Unit, Population) {
  PopulationDirector d;
  std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
  d.setBuilder(b);
  std::shared_ptr<Population> p = d.makeBig("elephant");
  ASSERT_EQ(p -> GetSize(), Population::BIG);
}

TEST(Unit, Mutation) {
  ASSERT_NO_FATAL_FAILURE(
      PopulationDirector d;
      std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
      d.setBuilder(b);
      std::shared_ptr<Population> p = d.makeBig("elephant");

      p -> mutate(Population::MutationType::SIZE);
      );
}

TEST(Unit, botChain) {
  ASSERT_NO_FATAL_FAILURE(
      std::vector<std::shared_ptr<Player> > players;
      players.assign(1, std::make_shared<Player>());
      PopulationDirector d;
      std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
      d.setBuilder(b);
      players[0]->addNewPopulation(d.makeAverage("pig - punk"));
      players[0]->addNewPopulation(d.makeBig("elephant"));
      GameEngine engine;
      engine.setPlayers(players);
      engine.generateMap();
      engine.botTurn(players[0]);
  );
}

TEST(Unit, Map) {
  Map map(10, 10);
  map.generate();

  ASSERT_EQ(map.getHeight(), 10);
  ASSERT_EQ(map.getWidth(), 10);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}