#include "SizeMutationHandler.h"

void SizeMutationHandler::change() {
  population->addMutation(Population::SIZE);
}