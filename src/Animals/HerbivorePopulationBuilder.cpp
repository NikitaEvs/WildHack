#include "PopulationBuilder.h"

class HerbivorePopulationBuilder : public PopulationBuilder {
 public:
  HerbivorePopulationBuilder() {
    p = std::make_shared<Population>();
  }
  void resetPopulation() override {
    p = std::make_shared<Population>();
  }
  void setType() override {
    p->SetType(Population::TypeName::HERBIVORE);
  }
  void setName(std::string name) override {
    p->SetName(name);
  }
  void setAmount(int32_t amount) override {
    p->SetAnimalAmount(amount);
  }
  void setHealth(int32_t health) override {
    p->SetHealth(health);
  }
  void setProductivity(int32_t productivity) override {
    p->SetProductivity(productivity);
  }
  void setBiologyDev(int32_t bio_dev) override {
    p->SetBiologyDev(bio_dev);
  }
  void setSize(Population::ParamType size) override {
    p->SetSize(size);
  }
  void setSafety(Population::ParamType safety) override {
    p->SetSafety(safety);
  }
  void setVelocity(Population::ParamType velocity) override {
    p->SetVelocity(velocity);
  }
  void setCover(Population::ParamType cover) override {
    p->SetCover(cover);
  }
  std::shared_ptr<Population> getProduct() override {
    return p;
  }
 private:
  std::shared_ptr<Population> p;
};
