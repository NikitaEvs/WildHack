#include "SafetyMutationHandler.h"

void SafetyMutationHandler::change() {
  population->addMutation(Population::SAFETY);
}