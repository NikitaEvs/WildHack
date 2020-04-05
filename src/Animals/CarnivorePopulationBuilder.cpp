#include "PopulationBuilder.h"

class CarnivorePopulationBuilder : public PopulationBuilder{
 private:
  std::shared_ptr<Population> p;
 public:
  CarnivorePopulationBuilder(){
    p = std::make_shared<Population>();
  }
  void setType() override {
    p->type = "carnivore";
  }
  void setName(std::string name){
    p->name = name;
  }
  void setAmount(int32_t a) override {
    p->animalAmount = a * 4 / 5;
  }
  void setHealth(int32_t h) override {
    p->health = h;
  }
  void setProductivity(int32_t pr) override {
    p->productivity = pr * 4 / 5;
  }
  void setWellBeing(int32_t w) override {
    p->wellBeing = w;
  }
  void setBiologyDev(int32_t b) override {
    p->biologyDev = std::min(b * 6 / 5, 40);
  }
  void setSize(Population::param s) override {
    p->size = s;
  }
  void setSafety(Population::param s) override {
    p->safety = s;
  }
  void setVelocity(Population::param v) override {
    p->velocity = v;;
  }
  void setCover(Population::param c) override {
    p->cover = c;
  }
  std::shared_ptr<Population> getProduct(){
    return p;
  }
};
