#include "Gui.h"

Gui::Gui(QObject *parent) : QObject(parent) {
  engine = std::make_shared<GameEngine>();
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

void Gui::init() {
  engine -> generateMap();
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
