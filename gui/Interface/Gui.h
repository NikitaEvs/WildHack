#pragma once

#include <qt5/QtCore/QObject>
#include <qt5/QtCore/QArgument>
#include <qt5/QtCore/QString>
#include <qt5/QtCore/QVariantList>

#include "Engine/GameEngine.h"

class Gui : public QObject {
  Q_OBJECT
  Q_PROPERTY(QVariantList map READ getMap WRITE setMap NOTIFY mapChanged)
  Q_PROPERTY(QVariantList populations READ getPopulations WRITE setPopulations NOTIFY populationsChanged)
  Q_PROPERTY(QVariantList currentPopulation READ getCurrentPopulation WRITE setCurrentPopulation NOTIFY currentPopulationChanged)
  Q_PROPERTY(QVariantList currentCell READ getCurrentCell WRITE setCurrentCell NOTIFY currentCellChanged)
  Q_PROPERTY(QVariant x READ getX WRITE setX NOTIFY xChanged)
  Q_PROPERTY(QVariant y READ getY WRITE setY NOTIFY yChanged)

 public:
  explicit Gui(QObject *parent = nullptr);

  const QVariantList & getMap();
  void setMap(const QVariantList &setMap);

  const QVariantList & getPopulations();
  void setPopulations(const QVariantList &setPopulations);

  const QVariantList & getCurrentPopulation();
  void setCurrentPopulation(const QVariantList &setPopulation);

  const QVariantList & getCurrentCell();
  void setCurrentCell(const QVariantList &setCurrentCell);

  const QVariant & getX();
  void setX(const QVariant &setX);

  const QVariant & getY();
  void setY(const QVariant &setY);

  std::shared_ptr<GameEngine> getEngine();

 public slots:
//  void multiply();
//  void migrate();

 signals:
  void mapChanged();
  void populationsChanged();
  void currentPopulationChanged();
  void currentCellChanged();
  void xChanged();
  void yChanged();

 private:
  QVariantList map;
  QVariantList populations;

  QVariantList currentPopulation;
  QVariantList currentCell;

  QVariant x;
  QVariant y;

  std::shared_ptr<GameEngine> engine;

  void fillMap();
  void fillPopulations();
};
