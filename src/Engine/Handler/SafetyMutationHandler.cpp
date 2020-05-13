#include "SafetyMutationHandler.h"

void SafetyMutationHandler::change() {
  population->mutate(Population::SAFETY);
}