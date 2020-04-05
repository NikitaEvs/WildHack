#ifndef PEACH_SRC_ANIMALS_POPULATIONBUILDER_H_
#define PEACH_SRC_ANIMALS_POPULATIONBUILDER_H_

#include <memory>
#include "Population.h"

class PopulationBuilder {
 public:
  virtual void setType() = 0;
  virtual void setName(std::string name) = 0;
  virtual void setAmount(int32_t a) = 0;
  virtual void setHealth(int32_t h) = 0;
  virtual void setProductivity(int32_t pr) = 0;
  virtual void setWellBeing(int32_t w) = 0;
  virtual void setBiologyDev(int32_t b) = 0;
  virtual void setSize(Population::param s) = 0;
  virtual void setSafety(Population::param s) = 0;
  virtual void setVelocity(Population::param v) = 0;
  virtual void setCover(Population::param c) = 0;
  virtual std::shared_ptr<Population> getProduct() = 0;
};

#endif //PEACH_SRC_ANIMALS_POPULATIONBUILDER_H_
