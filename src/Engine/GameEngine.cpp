#include "GameEngine.h"

void GameEngine::generateMap() {
  int32_t height = RandomGenerator::getInstance().randNormalInt(Config::getInstance().getHeight());
  int32_t width = RandomGenerator::getInstance().randNormalInt(Config::getInstance().getWidth());

  map = std::make_shared<Map>(height, width);
  map -> generate();
}

void GameEngine::fillMapPattern(std::vector<std::vector<int32_t> > &cells) {
  if (map == nullptr) {
    generateMap();
  }

  cells.assign(map -> getHeight(), std::vector<int32_t>(map -> getWidth()));

  for (size_t row = 0; row < map -> getHeight(); ++row) {
    for (size_t column = 0; column < map -> getWidth(); ++column) {
      cells[row][column] = static_cast<int32_t>((*map)[row][column] -> type);
    }
  }
}
