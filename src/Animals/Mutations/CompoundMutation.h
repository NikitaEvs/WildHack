#pragma once

#include <vector>

#include "MutationComponent.h"

class CompoundMutation : public MutationComponent {
 private:
  std::vector<std::shared_ptr<MutationComponent> > children;
 public:
  CompoundMutation();
  void add(std::shared_ptr<MutationComponent> m);
  void getMutation() override;
  void print(std::ostream &os) override;
};
