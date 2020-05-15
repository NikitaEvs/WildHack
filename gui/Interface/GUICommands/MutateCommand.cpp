#include "MutateCommand.h"

MutateCommand::MutateCommand(std::shared_ptr<GameEngine> engine) :
                             GUICommand(std::move(engine)) {}

void MutateCommand::setGoal(std::shared_ptr<Population> setGoal) {
  goal = std::move(setGoal);
}

void MutateCommand::setType(Population::MutationType type) {
  mutationType = type;
}

bool MutateCommand::execute() {

}
