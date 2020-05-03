#pragma once

#include <string>
#include <cstdint>
#include <iostream>

#include "Mutations/LeafMutation.h"
#include "Mutations/CompoundMutation.h"

class Population {
 public:
  enum param {
    VERY_SMALL,
    SMALL,
    AVERAGE,
    BIG,
    VERY_BIG
  };

 private:
  CompoundMutation mutationTree;

  static void switchParam(param &p, int32_t value);

 public:

  std::string type;
  std::string name;
  int32_t xPos = 0, yPos = 0;
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
  Population(Population const &p);
  void move(int32_t x, int32_t y);
  void dieOut(int32_t amount);
  void addMutation();
  void applyMutation();

  friend std::ostream &operator<<(std::ostream &os, Population &p);
};
