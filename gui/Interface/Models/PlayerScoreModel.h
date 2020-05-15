#pragma once

#include <QtCore/QAbstractListModel>

#include "Engine/Player/Player.h"
#include "Engine/GameEngine.h"

class PlayerScoreModel : public QAbstractListModel {
  Q_OBJECT
 public:
  enum roles {
    nameRole = Qt::UserRole + 1,
    scoreRole = Qt::UserRole + 2
  };

  explicit PlayerScoreModel(std::shared_ptr<GameEngine> setEngine, QObject *parent = nullptr);

  int rowCount(const QModelIndex & parent = QModelIndex()) const override ;
  QVariant data(const QModelIndex & index, int role) const;

 public slots:
  QHash<int, QByteArray> roleNames() const;
  void populate();

 private:
  QList<LightPlayer> playersList;
  std::shared_ptr<GameEngine> engine;

};
