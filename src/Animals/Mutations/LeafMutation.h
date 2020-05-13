#pragma once

#include "MutationComponent.h"

class LeafMutation : public MutationComponent {
 public:
  LeafMutation();
  void getMutation() override;
  void print(std::ostream &os) override;
};
