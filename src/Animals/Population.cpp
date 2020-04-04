#include "Population.h"

Population::Population() = default;
Population::Population(Population const& p){
  type = p.type;
  animalAmount = p.animalAmount;
  health = p.health;
  productivity = p.productivity;
  wellBeing = p.wellBeing;
  biologyDev = p.biologyDev;
  size = p.size;
  safety = p.safety;
  velocity = p.velocity;
  cover = p.cover;
}
void Population::move() = 0;
void Population::dieOut(int32_t amount){
  animalAmount -= amount * animalAmount / 100;
}
