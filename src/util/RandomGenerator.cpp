#include "RandomGenerator.h"

#include <memory>

RandomGenerator* RandomGenerator::randomPtr = nullptr;
RandomDestroyer RandomGenerator::destroyer;

RandomDestroyer::~RandomDestroyer() {
  delete instance;
}

void RandomDestroyer::initialize(RandomGenerator *initInstance) {
  instance = initInstance;
}

RandomGenerator::RandomGenerator() {
  generatorPtr = std::make_shared<std::mt19937>(randomDevice());
}

RandomGenerator& RandomGenerator::getInstance() {
  if (randomPtr == nullptr) {
    randomPtr = new RandomGenerator();
    destroyer.initialize(randomPtr);
  }
  return *randomPtr;
}

int32_t RandomGenerator::randInt(int32_t minVal, int32_t maxVal) {
  std::uniform_int_distribution<> distribution(minVal, maxVal);
  return distribution(*generatorPtr);
}

int32_t RandomGenerator::randNormalInt(int32_t mean, int32_t deviation) {
  std::normal_distribution<> distribution(mean, deviation);
  return std::round(distribution(*generatorPtr));
}

int32_t RandomGenerator::randNormalInt(std::pair<int32_t, int32_t> params) {
  return randNormalInt(params.first, params.second);
}