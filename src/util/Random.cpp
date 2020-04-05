#include "Random.h"

#include <memory>

Random* Random::randomPtr = nullptr;

Random::Random() {
  generatorPtr = std::make_shared<std::mt19937>(randomDevice());
}

std::shared_ptr<Random> Random::getInstance() {
  if (randomPtr == nullptr) {
    randomPtr = new Random();
  }
  return std::shared_ptr<Random>(randomPtr);;
}

int32_t Random::randInt(int32_t minVal, int32_t maxVal) {
  std::uniform_int_distribution<> distribution(minVal, maxVal);
  return distribution(*generatorPtr);
}

int32_t Random::randNormalInt(int32_t mean, int32_t deviation) {
  std::normal_distribution<> distribution(mean, deviation);
  return std::round(distribution(*generatorPtr));
}

int32_t Random::randNormalInt(std::pair<int32_t, int32_t> params) {
  return randNormalInt(params.first, params.second);
}