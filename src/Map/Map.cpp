#include "Map.h"

Map::Map(size_t columnNumber, size_t rowNumber) {
  map.assign(columnNumber, std::vector<std::shared_ptr<CellType> >(rowNumber, nullptr));
}

Map::iterator Map::begin() {
  return map.begin();
}

Map::iterator Map::end() {
  return map.end();
}

std::vector<std::shared_ptr<CellType> > &Map::operator[](size_t index) {
  return map[index];
}

void Map::loadFrom(std::istream &file) {
  nlohmann::json mapJSON;

  file >> mapJSON;

  size_t rowNumber = mapJSON["rowNumber"],
      columnNumber = mapJSON["columnNumber"];
  map.assign(columnNumber, std::vector<std::shared_ptr<CellType> >(rowNumber, nullptr));

  size_t row = 0,
      column = 0;

  for (auto cellJSON : mapJSON["data"]) {
    std::shared_ptr<CellType> cell = std::make_shared<CellType>();

    cell -> setType(cellJSON["cellType"]);
    cell -> setClimate(cellJSON["climateType"]);
    cell -> setPlantsCount(cellJSON["plantsCount"]);
    cell -> setWaterLevel(cellJSON["waterLevel"]);

    map[row][column] = std::move(cell);

    ++column;
    if (column == columnNumber) {
      column = 0;
      ++row;
    }
  }
}

void Map::saveTo(std::ostream &out) {
  nlohmann::json mapJSON;

  if (map.empty()) return;

  mapJSON["rowNumber"] = map.size();
  mapJSON["columnNumber"] = map[0].size();

  for (const auto &row : map) {
    for (const auto &cell : row) {
      nlohmann::json cellJSON;

      cellJSON["cellType"] = static_cast<int32_t>(cell -> getType());
      cellJSON["climateType"] = static_cast<int32_t>(cell -> getClimate());
      cellJSON["plantsCount"] = cell -> getPlantsCount();
      cellJSON["waterLevel"] = cell -> getWaterLevel();

      mapJSON["data"].push_back(cellJSON);
    }
  }

  out << mapJSON;
}

void Map::addCell(std::shared_ptr<CellType> &&cell, size_t row, size_t column) {
  map[row][column] = std::move(cell);
}

void Map::generate() {
  auto builder = std::make_shared<CellTypeBuilder>();
  CellTypeDirector director;
  director.setBuilder(builder);

  int32_t columns = map.size();
  int32_t rows = map[0].size();

  CellType::cellType prevType = CellType::WATER;

  for (int i = 0; i < columns; ++i) {
    for (int j = 0; j < rows; ++j) {
      if (map[i][j] == nullptr) {
        int32_t blockWidth = RandomGenerator::getInstance().randInt(1, std::min(columns / 3, columns - i));
        int32_t blockHeight = RandomGenerator::getInstance().randInt(1, std::min(rows / 3, rows - j));
        switch (prevType) {
          case CellType::WATER:prevType = CellType::STEPPE;
            break;
          case CellType::STEPPE:
            prevType = RandomGenerator::getInstance().randInt(0, 1) == 1 ? CellType::WATER : CellType::FOREST;
            break;
          case CellType::FOREST:
            prevType = RandomGenerator::getInstance().randInt(0, 1) == 1 ? CellType::STEPPE : CellType::TUNDRA;
            break;
          case CellType::TUNDRA:prevType = CellType::FOREST;
            break;
        }
        switch (prevType) {
          case CellType::WATER:
            for (int kI = 0; kI < blockWidth; ++kI) {
              for (int kJ = 0; kJ < blockHeight; ++kJ) {
                director.makeWaterCell();
                map[kI + i][kJ + j] = builder->getProduct();
              }
            }
            break;
          case CellType::STEPPE:
            for (int kI = 0; kI < blockWidth; ++kI) {
              for (int kJ = 0; kJ < blockHeight; ++kJ) {
                director.makeSteppeCell();
                map[kI + i][kJ + j] = builder->getProduct();
              }
            }
            break;
          case CellType::FOREST:
            for (int kI = 0; kI < blockWidth; ++kI) {
              for (int kJ = 0; kJ < blockHeight; ++kJ) {
                director.makeForestCell();
                map[kI + i][kJ + j] = builder->getProduct();
              }
            }
            break;
          case CellType::TUNDRA:
            for (int kI = 0; kI < blockWidth; ++kI) {
              for (int kJ = 0; kJ < blockHeight; ++kJ) {
                director.makeTundraCell();
                map[kI + i][kJ + j] = builder->getProduct();
              }
            }
            break;
        }
      }
    }
  }
}

size_t Map::getHeight() {
  return map.size();
}

size_t Map::getWidth() {
  return map[0].size();
}
