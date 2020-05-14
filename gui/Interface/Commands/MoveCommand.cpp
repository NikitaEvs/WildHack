#include "MoveCommand.h"

MoveCommand::MoveCommand(QObject *parent) :
                         QObject(parent) {}

void MoveCommand::setDestination(size_t destinationX, size_t destinationY) {
  x = destinationX;
  y = destinationY;
}

void MoveCommand::setGoal(std::shared_ptr<Population> population) {
  goal = std::move(population);
}

bool MoveCommand::execute() {
  std::cout << "kek" << std::endl;
}

void MoveCommand::kek() {
  std::cout << "kek" << std::endl;
}
