#ifndef SRC_UTIL_CONFIG_H_
#define SRC_UTIL_CONFIG_H_

#include <fstream>
#include <memory>

#include "json/json.hpp"

#define configFilePath "../resources/config/values.json"

class Config {
 private:
  nlohmann::json configJSON;

 protected:
  Config() = default;;
  static Config* configPtr;

 public:
  Config(Config &config) = delete;
  void operator = (const Config &) = delete;
  static std::shared_ptr<Config> getInstance();
  void readFile();

  /* Cell variables */

  /* Water */
  std::pair<int32_t, int32_t> getWaterWaterLevel();
  std::pair<int32_t, int32_t> getWaterPlantsCount();

  /* Forest */
  std::pair<int32_t, int32_t> getForestWaterLevel();
  std::pair<int32_t, int32_t> getForestPlantsCount();

  /* Steppe */
  std::pair<int32_t, int32_t> getSteppeWaterLevel();
  std::pair<int32_t, int32_t> getSteppePlantsCount();

  /* Tundra */
  std::pair<int32_t, int32_t> getTundraWaterLevel();
  std::pair<int32_t, int32_t> getTundraPlantsCount();

};

#endif //SRC_UTIL_CONFIG_H_
