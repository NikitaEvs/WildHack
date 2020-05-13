#pragma once

#include <memory>

#include "PopulationDirector.h"

class Handler{
 public:
  void handle();
  void setNext(std::shared_ptr<Handler> _next);
  void setPopulation(std::shared_ptr<Population> _population);
  virtual void setXYPos(int32_t x_pos, int32_t y_pos) = 0;
  ~Handler() = default;
 protected:
  virtual void change() = 0;
  std::shared_ptr<Handler> next = nullptr;
  std::shared_ptr<Population> population;
};