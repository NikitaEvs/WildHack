#ifndef PEACH_SRC_GUI_GUI_H_
#define PEACH_SRC_GUI_GUI_H_

#include <qt5/QtCore/QObject>
#include <qt5/QtCore/QArgument>
#include <qt5/QtCore/QString>
#include <qt5/QtCore/QVariantList>

#include "Engine/GameEngine.h"

class Gui : public QObject {
  Q_OBJECT
  Q_PROPERTY(QVariantList map READ getMap WRITE setMap NOTIFY mapChanged)

 public:
  explicit Gui(QObject *parent = nullptr);

  const QVariantList & getMap();
  void setMap(const QVariantList &setMap);

 public slots:
  void init();

 signals:
  void mapChanged();

 private:
  QVariantList map;
  std::shared_ptr<GameEngine> engine;

  void fillMap();
};

#endif //PEACH_SRC_GUI_GUI_H_
