#include "Command.h"

Command::Command(std::shared_ptr<GameEngine> engine) :
                receiver(std::move(engine)) {}

void Command::setReceiver(std::shared_ptr<GameEngine> engine) {
  receiver = engine;
}

void Command::setID(int32_t setID) {
  id = setID;
}
