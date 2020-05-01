#include "Config.h"

Config *Config::configPtr = nullptr;
ConfigDestroyer Config::destroyer;

ConfigDestroyer::~ConfigDestroyer() {
  delete instance;
}

void ConfigDestroyer::initialize(Config *initInstance) {
  instance = initInstance;
}

Config& Config::getInstance() {
  if (configPtr == nullptr) {
    configPtr = new Config();
    configPtr->readFile();
    destroyer.initialize(configPtr);
  }
  return *configPtr;
}

void Config::readFile() {
  std::ifstream fileIn(configFilePath);
  fileIn >> configJSON;
}

/* Map variables */

std::pair<int32_t, int32_t> Config::getHeight() {
  int32_t mean = configJSON["map"]["sizes"]["height"]["mean"];
  int32_t deviation = configJSON["map"]["sizes"]["height"]["deviation"];

  return std::make_pair(mean, deviation);
}

std::pair<int32_t, int32_t> Config::getWidth() {
  int32_t mean = configJSON["map"]["sizes"]["width"]["mean"];
  int32_t deviation = configJSON["map"]["sizes"]["width"]["deviation"];

  return std::make_pair(mean, deviation);
}

/* Cell variables */

/* Water */
std::pair<int32_t, int32_t> Config::getWaterWaterLevel() {
  int32_t mean = configJSON["cell"]["water"]["waterLevel"]["mean"];
  int32_t deviation = configJSON["cell"]["water"]["waterLevel"]["deviation"];

  return std::make_pair(mean, deviation);
}

std::pair<int32_t, int32_t> Config::getWaterPlantsCount() {
  int32_t mean = configJSON["cell"]["water"]["plantsCount"]["mean"];
  int32_t deviation = configJSON["cell"]["water"]["plantsCount"]["deviation"];

  return std::make_pair(mean, deviation);
}

/* Forest */
std::pair<int32_t, int32_t> Config::getForestWaterLevel() {
  int32_t mean = configJSON["cell"]["forest"]["waterLevel"]["mean"];
  int32_t deviation = configJSON["cell"]["forest"]["waterLevel"]["deviation"];

  return std::make_pair(mean, deviation);
}

std::pair<int32_t, int32_t> Config::getForestPlantsCount() {
  int32_t mean = configJSON["cell"]["forest"]["plantsCount"]["mean"];
  int32_t deviation = configJSON["cell"]["forest"]["plantsCount"]["deviation"];

  return std::make_pair(mean, deviation);
}

/* Steppe */
std::pair<int32_t, int32_t> Config::getSteppeWaterLevel() {
  int32_t mean = configJSON["cell"]["steppe"]["waterLevel"]["mean"];
  int32_t deviation = configJSON["cell"]["steppe"]["waterLevel"]["deviation"];

  return std::make_pair(mean, deviation);
}

std::pair<int32_t, int32_t> Config::getSteppePlantsCount() {
  int32_t mean = configJSON["cell"]["steppe"]["plantsCount"]["mean"];
  int32_t deviation = configJSON["cell"]["steppe"]["plantsCount"]["deviation"];

  return std::make_pair(mean, deviation);
}

/* Tundra */
std::pair<int32_t, int32_t> Config::getTundraWaterLevel() {
  int32_t mean = configJSON["cell"]["tundra"]["waterLevel"]["mean"];
  int32_t deviation = configJSON["cell"]["tundra"]["waterLevel"]["deviation"];

  return std::make_pair(mean, deviation);
}

std::pair<int32_t, int32_t> Config::getTundraPlantsCount() {
  int32_t mean = configJSON["cell"]["tundra"]["plantsCount"]["mean"];
  int32_t deviation = configJSON["cell"]["tundra"]["plantsCount"]["deviation"];

  return std::make_pair(mean, deviation);
}
/* ANIMALS */

std::pair<int32_t, int32_t> Config::getHerbivoreAverageAnimalAmount() {
  int32_t mean = configJSON["population"]["herbivore"]["average"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["average"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreAverageHealth() {
  int32_t mean = configJSON["population"]["herbivore"]["average"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["average"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreAverageProductivity() {
  int32_t mean = configJSON["population"]["herbivore"]["average"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["average"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreAverageWellBeing() {
  int32_t mean = configJSON["population"]["herbivore"]["average"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["average"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreAverageBiologyDev() {
  int32_t mean = configJSON["population"]["herbivore"]["average"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["average"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getHerbivoreVerySmallAnimalAmount() {
  int32_t mean = configJSON["population"]["herbivore"]["verySmall"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["verySmall"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVerySmallHealth() {
  int32_t mean = configJSON["population"]["herbivore"]["verySmall"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["verySmall"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVerySmallProductivity() {
  int32_t mean = configJSON["population"]["herbivore"]["verySmall"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["verySmall"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVerySmallWellBeing() {
  int32_t mean = configJSON["population"]["herbivore"]["verySmall"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["verySmall"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVerySmallBiologyDev() {
  int32_t mean = configJSON["population"]["herbivore"]["verySmall"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["verySmall"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getHerbivoreSmallAnimalAmount() {
  int32_t mean = configJSON["population"]["herbivore"]["small"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["small"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreSmallHealth() {
  int32_t mean = configJSON["population"]["herbivore"]["small"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["small"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreSmallProductivity() {
  int32_t mean = configJSON["population"]["herbivore"]["small"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["small"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreSmallWellBeing() {
  int32_t mean = configJSON["population"]["herbivore"]["small"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["small"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreSmallBiologyDev() {
  int32_t mean = configJSON["population"]["herbivore"]["small"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["small"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getHerbivoreVeryBigAnimalAmount() {
  int32_t mean = configJSON["population"]["herbivore"]["veryBig"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["veryBig"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVeryBigHealth() {
  int32_t mean = configJSON["population"]["herbivore"]["veryBig"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["veryBig"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVeryBigProductivity() {
  int32_t mean = configJSON["population"]["herbivore"]["veryBig"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["veryBig"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVeryBigWellBeing() {
  int32_t mean = configJSON["population"]["herbivore"]["veryBig"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["veryBig"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreVeryBigBiologyDev() {
  int32_t mean = configJSON["population"]["herbivore"]["veryBig"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["veryBig"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getHerbivoreBigAnimalAmount() {
  int32_t mean = configJSON["population"]["herbivore"]["big"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["big"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreBigHealth() {
  int32_t mean = configJSON["population"]["herbivore"]["big"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["big"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreBigProductivity() {
  int32_t mean = configJSON["population"]["herbivore"]["big"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["big"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreBigWellBeing() {
  int32_t mean = configJSON["population"]["herbivore"]["big"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["big"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getHerbivoreBigBiologyDev() {
  int32_t mean = configJSON["population"]["herbivore"]["big"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["herbivore"]["big"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getCarnivoreAverageAnimalAmount() {
  int32_t mean = configJSON["population"]["carnivore"]["average"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["average"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreAverageHealth() {
  int32_t mean = configJSON["population"]["carnivore"]["average"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["average"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreAverageProductivity() {
  int32_t mean = configJSON["population"]["carnivore"]["average"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["average"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreAverageWellBeing() {
  int32_t mean = configJSON["population"]["carnivore"]["average"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["average"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreAverageBiologyDev() {
  int32_t mean = configJSON["population"]["carnivore"]["average"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["average"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getCarnivoreVerySmallAnimalAmount() {
  int32_t mean = configJSON["population"]["carnivore"]["verySmall"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["verySmall"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVerySmallHealth() {
  int32_t mean = configJSON["population"]["carnivore"]["verySmall"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["verySmall"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVerySmallProductivity() {
  int32_t mean = configJSON["population"]["carnivore"]["verySmall"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["verySmall"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVerySmallWellBeing() {
  int32_t mean = configJSON["population"]["carnivore"]["verySmall"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["verySmall"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVerySmallBiologyDev() {
  int32_t mean = configJSON["population"]["carnivore"]["verySmall"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["verySmall"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getCarnivoreSmallAnimalAmount() {
  int32_t mean = configJSON["population"]["carnivore"]["small"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["small"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreSmallHealth() {
  int32_t mean = configJSON["population"]["carnivore"]["small"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["small"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreSmallProductivity() {
  int32_t mean = configJSON["population"]["carnivore"]["small"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["small"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreSmallWellBeing() {
  int32_t mean = configJSON["population"]["carnivore"]["small"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["small"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreSmallBiologyDev() {
  int32_t mean = configJSON["population"]["carnivore"]["small"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["small"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getCarnivoreVeryBigAnimalAmount() {
  int32_t mean = configJSON["population"]["carnivore"]["veryBig"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["veryBig"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVeryBigHealth() {
  int32_t mean = configJSON["population"]["carnivore"]["veryBig"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["veryBig"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVeryBigProductivity() {
  int32_t mean = configJSON["population"]["carnivore"]["veryBig"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["veryBig"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVeryBigWellBeing() {
  int32_t mean = configJSON["population"]["carnivore"]["veryBig"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["veryBig"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreVeryBigBiologyDev() {
  int32_t mean = configJSON["population"]["carnivore"]["veryBig"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["veryBig"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}


std::pair<int32_t, int32_t> Config::getCarnivoreBigAnimalAmount() {
  int32_t mean = configJSON["population"]["carnivore"]["big"]["animalAmount"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["big"]["animalAmount"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreBigHealth() {
  int32_t mean = configJSON["population"]["carnivore"]["big"]["health"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["big"]["health"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreBigProductivity() {
  int32_t mean = configJSON["population"]["carnivore"]["big"]["productivity"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["big"]["productivity"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreBigWellBeing() {
  int32_t mean = configJSON["population"]["carnivore"]["big"]["wellBeing"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["big"]["wellBeing"]["deviation"];

  return std::make_pair(mean, deviation);
}
std::pair<int32_t, int32_t> Config::getCarnivoreBigBiologyDev() {
  int32_t mean = configJSON["population"]["carnivore"]["big"]["biologyDev"]["mean"];
  int32_t deviation = configJSON["population"]["carnivore"]["big"]["biologyDev"]["deviation"];

  return std::make_pair(mean, deviation);
}