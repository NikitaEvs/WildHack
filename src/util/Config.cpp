#include "Config.h"

Config* Config::configPtr = nullptr;

std::shared_ptr<Config> Config::getInstance() {
  if (configPtr == nullptr) {
    configPtr = new Config();
    configPtr -> readFile();
  }
  return std::shared_ptr<Config>(configPtr);
}

void Config::readFile() {
  std::ifstream fileIn(configFilePath);
  fileIn >> configJSON;
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
