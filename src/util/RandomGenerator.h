#pragma once

#include <random>
#include <memory>

class RandomGenerator;

class RandomDestroyer {
 public:
  ~RandomDestroyer();
  void initialize(RandomGenerator *initInstance);

 private:
  RandomGenerator *instance;
};

class RandomGenerator {
 public:
  RandomGenerator(RandomGenerator &random) = delete;
  void operator = (const RandomGenerator &) = delete;

  static RandomGenerator& getInstance();

  int32_t randInt(int32_t minVal, int32_t maxVal);
  int32_t randNormalInt(int32_t mean, int32_t deviation);
  int32_t randNormalInt(std::pair<int32_t, int32_t> params);

 private:
  std::random_device randomDevice;
  std::shared_ptr<std::mt19937> generatorPtr;

 protected:
  RandomGenerator();
  ~RandomGenerator() = default;

  static RandomGenerator* randomPtr;
  static RandomDestroyer destroyer;
  friend class RandomDestroyer;
};
