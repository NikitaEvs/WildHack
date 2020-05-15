#include "StopCommand.h"

StopCommand::StopCommand(std::shared_ptr<GameEngine> engine) :
                         Command(std::move(engine)) {}

bool StopCommand::execute() {
  receiver -> finishStep();
  return true;
}
