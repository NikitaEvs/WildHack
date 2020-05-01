#include <vector>
#include <iostream>
#include <memory>
#include "CompoundMutation.h"
#include "LeafMutation.h"

CompoundMutation::CompoundMutation() = default;

void CompoundMutation::add(std::shared_ptr<MutationComponent> m) {
  children.push_back(m);
}

void CompoundMutation::getMutation() {
  for (auto ch = children.begin(); ch != children.end(); ++ch) {
    (*ch)->getMutation();
    health += (*ch)->health;
    productivity += (*ch)->productivity;
    wellBeing += (*ch)->wellBeing;
    size += (*ch)->size;
    safety += (*ch)->safety;
    velocity += (*ch)->velocity;
    cover += (*ch)->cover;
  }
}

void CompoundMutation::print(std::ostream &os) {
  os << "HEALTH SHARE " << health << " / 100" << std::endl;
  os << "PRODUCTIVITY SHARE " << productivity << " / 100" << std::endl;
  os << "WELLBEING SHARE " << wellBeing << " / 100" << std::endl;
  os << "SIZE SWITCH " << size << std::endl;
  os << "SAFETY SWITCH " << safety << std::endl;
  os << "VELOCITY SWITCH " << velocity << std::endl;
  os << "COVER SWITCH " << cover << std::endl;
  os << "~~~~~~~~~~~~~~~CHILDREN_BEGIN~~~~~~~~~~~~~~~~~~" << std::endl;
  for (int i = 0; i < children.size(); ++i) {
    children[i]->print(os);
  }
  os << "~~~~~~~~~~~~~~~CHILDREN_END~~~~~~~~~~~~~~~~~~" << std::endl;
}
