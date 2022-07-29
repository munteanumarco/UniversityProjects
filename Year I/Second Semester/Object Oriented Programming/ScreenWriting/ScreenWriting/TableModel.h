#pragma once
#include <QAbstractTableModel>
#include "Cont.h"


class TableModel : public QAbstractTableModel {
private:
	Controller& cont;
public:
	TableModel(Controller& cont);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	
	void addIdea(Idea i);
	vector<Idea> getIdeas();
	vector<Writer>& getWriters();
	void acceptIdea(int index);
};