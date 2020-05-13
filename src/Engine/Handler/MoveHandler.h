#pragma once

#include "Handler.h"

class MoveHandler: public Handler{
 public:
  void setXYPos(int32_t x_pos, int32_t y_pos) override ;
 private:
  int32_t xPos = -1, yPos = -1;
  void change() override ;
};