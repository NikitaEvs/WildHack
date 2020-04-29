#ifndef PEACH_SRC_ENGINE_GAMEENGINE_H_
#define PEACH_SRC_ENGINE_GAMEENGINE_H_

#include <memory>
#include <vector>

#include "Map/Map.h"
#include "Animals/Population.h"

class GameEngine {
 private:
  std::shared_ptr<Map> map;
  std::vector<std::shared_ptr<Population> > populations;

 public:
  GameEngine() = default;

  void init(size_t height, size_t width, const std::pair<int64_t, int64_t>& center);

};

#endif //PEACH_SRC_ENGINE_GAMEENGINE_H_
