#include "VelocityMutationHandler.h"

void VelocityMutationHandler::change() {
  population->mutate(Population::VELOCITY);
}