#ifndef PEACH_SRC_ANIMALS_POPULATION_H_
#define PEACH_SRC_ANIMALS_POPULATION_H_

class Population {
 public:
  std::string type;
  int32_t animalAmount; //[0, 10000]
  int32_t health; //[0, 100] %
  int32_t productivity; //[0, 10] - average amount of children from one parent
  int32_t wellBeing; //[0, 100] %
  int32_t biologyDev; //[0, 100] %
  param size;
  param safety;
  param velocity;
  param cover;

  enum param {
    VERY_SMALL,
    SMALL,
    AVERAGE,
    BIG,
    VERY_BIG
  };
  Population();
  Population(Population const& p);
  void move();
  void dieOut(int32_t amount);
};

#endif //PEACH_SRC_ANIMALS_POPULATION_H_