#include "Command.h"

void Command::setReceiver(std::shared_ptr<GameEngine> engine) {
  receiver = std::move(engine);
}
