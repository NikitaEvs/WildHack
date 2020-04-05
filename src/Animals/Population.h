#ifndef PEACH_SRC_ANIMALS_POPULATION_H_
#define PEACH_SRC_ANIMALS_POPULATION_H_
#include <string>
#include <cstdint>
#include <iostream>
class Population {
 public:
  enum param {
    VERY_SMALL,
    SMALL,
    AVERAGE,
    BIG,
    VERY_BIG
  };

  std::string type;
  std::string name;
  int32_t xPos, yPos;
  int32_t animalAmount; //[0, 10000]
  int32_t health; //[0, 100] %
  int32_t productivity; //[0, 10] - average amount of children from one parent
  int32_t wellBeing; //[0, 100] %
  int32_t biologyDev; //[0, 100] %
  param size;
  param safety;
  param velocity;
  param cover;

  Population();
  Population(Population const& p);
  void move(int x, int y);
  void dieOut(int32_t amount);
};

std::ostream& operator << (std::ostream &os, Population &p);
#endif //PEACH_SRC_ANIMALS_POPULATION_H_