#include "MoveCommand.h"

void MoveCommand::setDestination(size_t destinationX, size_t destinationY) {
  x = destinationX;
  y = destinationY;
}

void MoveCommand::setGoal(std::shared_ptr<Population> setGoal) {
  goal = std::move(setGoal);
}

bool MoveCommand::execute() {
  std::cout << "Move" << std::endl;
  receiver -> populationMove(goal, x, y);
  return true;
}
