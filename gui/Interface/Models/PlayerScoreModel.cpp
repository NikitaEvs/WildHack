#include "PlayerScoreModel.h"

PlayerScoreModel::PlayerScoreModel(std::shared_ptr<GameEngine> setEngine, QObject *parent) :
                                   QAbstractListModel(parent),
                                   engine(std::move(setEngine)){}

int PlayerScoreModel::rowCount(const QModelIndex &parent) const {
  std::cout << "Size: " << playersList.size() << std::endl;
  return playersList.size();
}

QVariant PlayerScoreModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  std::cout << "Ros: " << index.row() << std::endl;

  if (role == nameRole) {
    return QVariant(QString::fromStdString(playersList[index.row()].getName()));
  } else if (role == scoreRole) {
    return QVariant(static_cast<int>(playersList[index.row()].getScore()));
  }

  return QVariant();
}

QHash<int, QByteArray> PlayerScoreModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[nameRole] = "name";
  roles[scoreRole] = "score";
  return roles;
}

void PlayerScoreModel::populate() {
  beginInsertRows(QModelIndex(), rowCount(), rowCount());

  auto players = engine -> getLightPlayers();;

  for (const auto & player : players) {
    std::cout << player -> getName() << std::endl;
    playersList.push_back(*player);
  }

  endInsertRows();
}
