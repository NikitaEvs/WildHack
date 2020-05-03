#pragma once

#include <memory>
#include <vector>

#include "Map/Map.h"
#include "Animals/Population.h"
#include "util/Config.h"
#include "util/RandomGenerator.h"

class GameEngine {
 public:
  GameEngine() = default;

  void generateMap();

  void fillMapPattern(std::vector<std::vector<int32_t> > &cells);

 private:
  std::shared_ptr<Map> map;
  std::vector<std::shared_ptr<Population> > populations;
};
