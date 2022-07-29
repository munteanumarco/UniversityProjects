#pragma once
#include <qtableview.h>
#include "trench_repo.h"
class TrenchTableModel : public QAbstractTableModel {
private:
	vector<TrenchCoat> basket;
public:
	TrenchTableModel(vector<TrenchCoat> basket);
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	void update();
};