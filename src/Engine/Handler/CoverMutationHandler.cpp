#include "CoverMutationHandler.h"

void CoverMutationHandler::change() {
  population->mutate(Population::COVER);
}