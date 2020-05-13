#pragma once

#include "Handler.h"

class CoverMutationHandler: public Handler{
 public:
  void setXYPos(int32_t x_pos, int32_t y_pos) override {};
 private:
  void change() override ;
};