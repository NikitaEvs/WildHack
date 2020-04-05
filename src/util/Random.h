#ifndef SRC_UTIL_RANDOM_H_
#define SRC_UTIL_RANDOM_H_

#include <random>
#include <memory>

class Random;

class RandomDestroyer {
 private:
  Random *instance;
 public:
  ~RandomDestroyer();
  void initialize(Random *initInstance);
};

class Random {
 private:
  std::random_device randomDevice;
  std::shared_ptr<std::mt19937> generatorPtr;

 protected:
  Random();
  ~Random() {}
  static Random* randomPtr;
  static RandomDestroyer destroyer;
  friend class RandomDestroyer;

 public:
  Random(Random &random) = delete;
  void operator = (const Random &) = delete;
  static Random& getInstance();
  int32_t randInt(int32_t minVal, int32_t maxVal);
  int32_t randNormalInt(int32_t mean, int32_t deviation);
  int32_t randNormalInt(std::pair<int32_t, int32_t> params);
};

#endif //SRC_UTIL_RANDOM_H_
