#include "SplitCommand.h"

SplitCommand::SplitCommand(std::shared_ptr<GameEngine> engine) :
                           GUICommand(std::move(engine)) {}

void SplitCommand::setGoal(std::shared_ptr<Population> setGoal) {
  goal = std::move(setGoal);
}

void SplitCommand::setDestination(size_t destinationX, size_t destinationY) {
  x = destinationX;
  y = destinationY;
}

bool SplitCommand::execute() {
  return false;
}
