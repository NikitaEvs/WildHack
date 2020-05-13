#pragma once

#include <memory>

#include "PopulationDirector.h"

class Handler{
 public:
  void handle();
  void setNext(std::shared_ptr<Handler> _next);
  void setPopulation(std::shared_ptr<Population> _population);
 protected:
  virtual void change() = 0;
  std::shared_ptr<Handler> next = nullptr;
  std::shared_ptr<Population> population;
};