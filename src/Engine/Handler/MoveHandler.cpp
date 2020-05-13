#include "MoveHandler.h"

void MoveHandler::change() {
  if (xPos == -1 || yPos == -1) {
    throw std::runtime_error("Position to move to was not chosen");
  } else {
    population->move(xPos, yPos);
  }
}
void MoveHandler::setXYPos(int32_t x_pos, int32_t y_pos) {
  xPos = x_pos;
  yPos = y_pos;
}
