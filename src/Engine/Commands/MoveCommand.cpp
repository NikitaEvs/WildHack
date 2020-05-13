#include "MoveCommand.h"

MoveCommand::MoveCommand(std::shared_ptr<GameEngine> engine, std::shared_ptr<Population> population) :
                         receiver(std::move(engine)),
                         goal(std::move(population)) {}

void MoveCommand::setDestination(size_t destinationX, size_t destinationY) {
  x = destinationX;
  y = destinationY;
}

bool MoveCommand::execute() {
  return false;
}
