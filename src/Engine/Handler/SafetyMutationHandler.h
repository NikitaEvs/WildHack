#pragma once

#include "Handler.h"

class SafetyMutationHandler: public Handler{
 private:
  void change() override ;
};