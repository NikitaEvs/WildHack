#include "SizeMutationHandler.h"

void SizeMutationHandler::change() {
  population->mutate(Population::SIZE);
}