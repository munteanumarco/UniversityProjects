#include "TableModel.h"

TableModel::TableModel(Controller& cont)
	: cont(cont)
{
}

int TableModel::rowCount(const QModelIndex& parent) const
{
	return this->cont.getIdeas().size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Idea i = this->cont.getIdeas()[row];

	if (role == Qt::DisplayRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(i.getDescription());
			break;
		case 1:
			return  QString::fromStdString(i.getStatus());
			break;
		case 2:
			return  QString::fromStdString(i.getCreator());
			break;
		case 3:
			return  QString::fromStdString(to_string(i.getAct()));
			break;
		default:
			break;
		}
	}

	return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal)
	{
		if (role == Qt::DisplayRole)
		{
			switch (section)
			{
			case 0:
				return QString("Description");
				break;
			case 1:
				return QString("Status");
				break;
			case 2:
				return QString("Creator");
				break;
			case 3:
				return QString("Act");
				break;
			default:
				break;
			}
		}
	}
	return QVariant();
}

void TableModel::addIdea(Idea i)
{
	if (i.getAct() != 1 && i.getAct() != 2 && i.getAct() != 3)
	{
		throw exception("Invalid act!");
	}
	if (!this->cont.checkUniqueDescription(i))
	{
		throw exception("Duplicate description!");
	}
	beginResetModel();
	this->cont.addIdea(i);
	endResetModel();
}

vector<Idea> TableModel::getIdeas()
{
	return this->cont.getIdeas();
}

vector<Writer>& TableModel::getWriters()
{
	return this->cont.getWriters();
}

void TableModel::acceptIdea(int index)
{
	beginResetModel();
	this->cont.acceptIdea(index);
	endResetModel();
}
