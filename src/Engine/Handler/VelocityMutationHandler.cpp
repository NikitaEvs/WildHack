#include "VelocityMutationHandler.h"

void VelocityMutationHandler::change() {
  population->addMutation(Population::VELOCITY);
}