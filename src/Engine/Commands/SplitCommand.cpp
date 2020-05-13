#include "SplitCommand.h"

SplitCommand::SplitCommand(std::shared_ptr<GameEngine> engine,
                           std::shared_ptr<Population> population) :
                           goal(std::move(population)) {
  setReceiver(std::move(engine));
}

bool SplitCommand::execute() {
  return false;
}
