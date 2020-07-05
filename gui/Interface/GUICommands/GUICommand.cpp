#include "GUICommand.h"

GUICommand::GUICommand(std::shared_ptr<GameEngine> engine) :
                       receiver(std::move(engine)) {}

void GUICommand::setReceiver(std::shared_ptr<GameEngine> engine) {
  receiver = std::move(engine);
}

void GUICommand::setID(int32_t setID) {
  id = setID;
}
