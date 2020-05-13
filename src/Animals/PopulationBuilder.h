#pragma once

#include <memory>
#include "Population.h"

class PopulationBuilder {
 public:
  virtual void setType() = 0;
  virtual void setName(std::string name) = 0;
  virtual void setAmount(int32_t amount) = 0;
  virtual void setHealth(int32_t health) = 0;
  virtual void setProductivity(int32_t productivity) = 0;
  virtual void setBiologyDev(int32_t bio_dev) = 0;
  virtual void setSize(Population::ParamType size) = 0;
  virtual void setSafety(Population::ParamType safety) = 0;
  virtual void setVelocity(Population::ParamType velocity) = 0;
  virtual void setCover(Population::ParamType cover) = 0;
  virtual std::shared_ptr<Population> getProduct() = 0;
};
