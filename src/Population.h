class Population {
 public:
  std::string type;
  int32_t animalAmount; //[0, 10000]
  int32_t health; //[0, 100] %
  int32_t productivity; //[0, 10] - average amount of children from one parent
  int32_t wellBeing; //[0, 100] %
  int32_t biologyDev; //[0, 100] %
  param size;
  param safety;
  param velocity;
  param cover;

  enum param {
    VERY_SMALL,
    SMALL,
    AVERAGE,
    BIG,
    VERY_BIG
  };
  Population() = default;
  Population(Population const& p){
      type = p.type;
      animalAmount = p.animalAmount;
      health = p.health;
      productivity = p.productivity;
      wellBeing = p.wellBeing;
      biologyDev = p.biologyDev;
      size = p.size;
      safety = p.safety;
      velocity = p.velocity;
      cover = p.cover;
  }
  void move() = 0;
  void dieOut(int32_t amount){
      animalAmount -= amount * animalAmount / 100;
  }
};

class PopulationBuilder{
 private:
  Population p;
 public:
  virtual void setType() = 0;
  virtual void setAmount(int32_t a) = 0;
  virtual void setHealth(int32_t h) = 0;
  virtual void setProductivity(int32_t pr) = 0;
  virtual void setWellBeing(int32_t w) = 0;
  virtual void setBiologyDev(int32_t b) = 0;
  virtual void setSize(Population::param s) = 0;
  virtual void setSafety(Population::param s) = 0;
  virtual void setVelocity(Population::param v) = 0;
  virtual void setCover(Population::param c) = 0;
  std::shared_ptr<Population>Population getPopulation(){
      return std::shared_ptr<Population>(p);
  }
};

class HerbivorePopulationBuilder : public PopulationBuilder{
 private:
  Population p;
 public:
  HerbivorePopulationBuilder(){
      p = Population();
  }
  void setType() override {
      p.type = "herbivore";
  }
  void setAmount(int32_t a) override {
      p.animalAmount = a;
  }
  void setHealth(int32_t h) override {
      p.health = h;
  }
  void setProductivity(int32_t pr) override {
      p.productivity = pr;
  }
  void setWellBeing(int32_t w) override {
      p.wellBeing = w;
  }
  void setBiologyDev(int32_t b) override {
      p.biologyDev = b;
  }
  void setSize(Population::param s) override {
      p.size = s;
  }
  void setSafety(Population::param s) override {
      p.safety = s;
  }
  void setVelocity(Population::param v) override {
      p.velocity = v;
  }
  void setCover(Population::param c) override {
      p.cover = c;
  }
};

class CarnivorePopulationBuilder : public PopulationBuilder{
 private:
  Population p;
 public:
  CarnivorePopulationBuilder(){
      p = Population();
  }
  void setType() override {
      p.type = "carnivore";
  }
  void setAmount(int32_t a) override {
      p.animalAmount = a * 4 / 5;
  }
  void setHealth(int32_t h) override {
      p.health = h;
  }
  void setProductivity(int32_t pr) override {
      p.productivity = pr * 4 / 5;
  }
  void setWellBeing(int32_t w) override {
      p.wellBeing = w;
  }
  void setBiologyDev(int32_t b) override {
      p.biologyDev = std::min(b * 6 / 5, 40);
  }
  void setSize(Population::param s) override {
      p.size = s;
  }
  void setSafety(Population::param s) override {
      p.safety = s;
  }
  void setVelocity(Population::param v) override {
      p.velocity = std::min(v * 6 / 5, 70);;
  }
  void setCover(Population::param c) override {
      p.cover = c * 4 / 5;
  }
};

class PopulationDirector{
  PopulationBuilder builder;
 public:
  Population makeSmall(std::string type){
      if(type == "herbivore"){
          builder = HerbivorePopulationBuilder();
      } else {
          builder = CarnivorePopulationBuilder();
      }
      builder.setType();
      builder.setAmount(500);
      builder.setHealth(60);
      builder.setProductivity(8);
      builder.setWellBeing(50);
      builder.setBiologyDev(20);
      builder.setSize(Population::SMALL);
      builder.setSafety(Population::AVERAGE);
      builder.setVelocity(Population::SMALL);
      builder.setCover(Population::SMALL);
  }
  Population makeAverage(std::string type){
      if(type == "herbivore"){
          builder = HerbivorePopulationBuilder();
      } else {
          builder = CarnivorePopulationBuilder();
      }
      builder.setType();
      builder.setAmount(200);
      builder.setHealth(70);
      builder.setProductivity(4);
      builder.setWellBeing(50);
      builder.setBiologyDev(20);
      builder.setSize(Population::AVERAGE);
      builder.setSafety(Population::AVERAGE);
      builder.setVelocity(Population::AVERAGE);
      builder.setCover(Population::AVERAGE);
  }
  Population makeBig(std::string type){
      if(type == "herbivore"){
          builder = HerbivorePopulationBuilder();
      } else {
          builder = CarnivorePopulationBuilder();
      }
      builder.setType();
      builder.setAmount(50);
      builder.setHealth(80);
      builder.setProductivity(1);
      builder.setWellBeing(60);
      builder.setBiologyDev(20);
      builder.setSize(Population::BIG);
      builder.setSafety(Population::BIG);
      builder.setVelocity(Population::AVERAGE);
      builder.setCover(Population::AVERAGE);
  }
};