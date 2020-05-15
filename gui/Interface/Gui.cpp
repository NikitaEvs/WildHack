#include "Gui.h"
#include "Animals/Population.h"

Gui::Gui(std::shared_ptr<GameEngine> setEngine, QObject *parent) : QObject(parent) {
  engine = setEngine;

  moveCommand = std::make_shared<MoveCommand>();
  moveCommand -> setReceiver(setEngine);
  splitCommand = std::make_shared<SplitCommand>(engine);
  mutateCommand = std::make_shared<MutateCommand>(engine);
  stopCommand = std::make_shared<StopCommand>(engine);
}

const QVariantList& Gui::getMap() {
  if (map.empty()) {
    fillMap();
  }

  return map;
}

void Gui::setMap(const QVariantList &setMap) {
  map = setMap;
}

const QVariantList &Gui::getPopulations() {
  if (populations.empty()) {
    fillPopulations();
  } else {
    updatePopulations();
  }

  return populations;
}

void Gui::setPopulations(const QVariantList &setPopulations) {
  populations = setPopulations;
}

const QVariantList &Gui::getCurrentPopulation() {
  int32_t xPos = 0, yPos = 0;

  if (x.canConvert<int32_t>()) {
    xPos = x.value<int32_t>();
  } else {
    std::cerr << "Variant non int" << std::endl;
  }

  if (y.canConvert<int32_t>()) {
    yPos = y.value<int32_t>();
  } else {
    std::cerr << "Variant non int" << std::endl;
  }

  auto population = engine -> getPopulation(xPos, yPos);
  currentPopulation.clear();

  if(population == nullptr) {
    currentPopulation.push_back(-1);
    return currentPopulation;
  }

  currentPopulation.push_back(static_cast<int32_t>(population -> GetSize()));
  currentPopulation.push_back(static_cast<int32_t>(population -> GetType()));
  currentPopulation.push_back(QString::fromStdString(population -> GetName()));
  currentPopulation.push_back(static_cast<int32_t>(population -> GetSafety()));
  currentPopulation.push_back(static_cast<int32_t>(population -> GetVelocity()));
  currentPopulation.push_back(static_cast<int32_t>(population -> GetCover()));
  currentPopulation.push_back(population -> GetHealth());
  currentPopulation.push_back(population -> GetProductivity());
  currentPopulation.push_back(population -> GetBiologyDev());
  currentPopulation.push_back(population -> GetAvailableStep());
  currentPopulation.push_back(population -> GetAnimalAmount());
  currentPopulation.push_back(population -> GetPlayerNumber());

  return currentPopulation;
}

void Gui::setCurrentPopulation(const QVariantList &setPopulation) {
  currentPopulation = setPopulation;
}

const QVariantList &Gui::getCurrentCell() {
  int32_t xPos = 0, yPos = 0;

  if (x.canConvert<int32_t>()) {
    xPos = x.value<int32_t>();
  } else {
    std::cerr << "Variant non int" << std::endl;
  }

  if (y.canConvert<int32_t>()) {
    yPos = y.value<int32_t>();
  } else {
    std::cerr << "Variant non int" << std::endl;
  }

  auto cell = engine -> getCell(xPos, yPos);
  currentCell.clear();

  currentCell.push_back(static_cast<int32_t>(cell -> getClimate()));
  currentCell.push_back(static_cast<int32_t>(cell -> getType()));
  currentCell.push_back(cell -> getWaterLevel());
  currentCell.push_back(cell -> getPlantsCount());
  currentCell.push_back(cell -> getCarnivoreCount());
  currentCell.push_back(cell -> getHerbivoreCount());

  return currentCell;
}

void Gui::setCurrentCell(const QVariantList &setCurrentCell) {
  currentCell = setCurrentCell;
}

const QVariant &Gui::getX() {
  return x;
}

void Gui::setX(const QVariant &setX) {
  x = setX;
}

const QVariant &Gui::getY() {
  return y;
}

void Gui::setY(const QVariant &setY) {
  y = setY;
}

const QVariant &Gui::getID() {
  id = engine -> getCurrentID();

  return id;
}

void Gui::setID(const QVariant &setID) {
  id = setID;
}

std::shared_ptr<GameEngine> Gui::getEngine() {
  return engine;
}

void Gui::update(bool end) {
  if (end) {
    emit endGame();
  } else {
    emit requestUpdate();
  }
}

void Gui::fillMap() {
  std::vector<std::vector<int32_t> > pattern;

  engine -> fillMapPattern(pattern);

  for (auto& row : pattern) {
    QVariantList rowList;
    rowList.reserve(row.size());
    std::copy(row.begin(), row.end(), std::back_inserter(rowList));

    map.push_back(rowList);
  }
}

void Gui::fillPopulations() {
  std::vector<LightPopulation> pattern;

  engine -> fillPopulationPattern(pattern);

  for (auto& population : pattern) {
    QVariantList populationList;

    populationList.push_back(QString::fromStdString(population.getName()));
    populationList.push_back(population.getXPos());
    populationList.push_back(population.getYPos());

    populations.push_back(populationList);
  }
}

void Gui::updatePopulations() {
  populations.clear();
  std::vector<LightPopulation> pattern;

  engine -> getPopulationPattern(pattern);

  for (auto& population : pattern) {
    QVariantList populationList;

    populationList.push_back(QString::fromStdString(population.getName()));
    populationList.push_back(population.getXPos());
    populationList.push_back(population.getYPos());

    populations.push_back(populationList);
  }
}

void Gui::multiply() {
  std::cout << "Multiply" << std::endl;

  if (selectedPopulation -> GetAvailableStep() > 0) {
    selectedPopulation -> SetAvailableStep(selectedPopulation->GetAvailableStep() - 1);

    splitCommand -> setGoal(selectedPopulation);
    splitCommand -> setDestination(x.toInt(), y.toInt());

    splitCommand->execute();
  }
}

void Gui::select() {
  std::cout << "Select" << std::endl;

  selectedPopulation = engine -> getPopulation(x.toInt(), y.toInt());
}

void Gui::migrate() {
  std::cout << "Migrate" << std::endl;

  if (selectedPopulation -> GetAvailableStep() > 0) {
    selectedPopulation -> SetAvailableStep(selectedPopulation -> GetAvailableStep() - 1);

    moveCommand -> setGoal(selectedPopulation);
    std::cout << x.toInt() << " " << y.toInt() << std::endl;
    moveCommand -> setDestination(x.toInt(), y.toInt());

    moveCommand -> execute();
  }
}

void Gui::mutate(int type) {
  std::cout << "Mutate " << static_cast<int32_t>(type) << std::endl;

  if (selectedPopulation -> GetAvailableStep() > 0) {
    selectedPopulation -> SetAvailableStep(selectedPopulation -> GetAvailableStep() - 1);

    mutateCommand -> setGoal(selectedPopulation);
    mutateCommand -> setType(static_cast<Population::MutationType>(type));
    mutateCommand -> execute();
  }
}

void Gui::stop() {
  std::cout << "Stop" << std::endl;

  stopCommand -> execute();
}

bool Gui::checkPopulation(int posX, int posY) {
  if (engine -> getPopulation(posX, posY)) {
    return false;
  } else {
    return true;
  }
}
