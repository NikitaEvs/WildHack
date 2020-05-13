#include "StopCommand.h"

StopCommand::StopCommand(std::shared_ptr<GameEngine> engine) {
    setReceiver(std::move(engine));
}

bool StopCommand::execute() {
  return false;
}
