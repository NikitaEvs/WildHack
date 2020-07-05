#include "StopCommand.h"

StopCommand::StopCommand(std::shared_ptr<GameEngine> engine) :
                         GUICommand(std::move(engine)) {}

bool StopCommand::execute() {
  receiver -> finishStep();
  return true;
}
