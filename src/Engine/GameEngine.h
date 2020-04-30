#ifndef PEACH_SRC_ENGINE_GAMEENGINE_H_
#define PEACH_SRC_ENGINE_GAMEENGINE_H_

#include <memory>
#include <vector>

#include "Map/Map.h"
#include "Animals/Population.h"
#include "util/Config.h"
#include "util/Random.h"

class GameEngine {
 private:
  std::shared_ptr<Map> map;
  std::vector<std::shared_ptr<Population> > populations;

 public:
  GameEngine() = default;

  void generateMap();
  void fillMapPattern(std::vector<std::vector<int32_t> > &cells);
};

#endif //PEACH_SRC_ENGINE_GAMEENGINE_H_
