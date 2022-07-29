#include "TrenchModel.h"

TrenchTableModel::TrenchTableModel(vector<TrenchCoat> basket) : basket(basket)
{
}

int TrenchTableModel::rowCount(const QModelIndex& parent) const
{
	return this->basket.size();
}

int TrenchTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant TrenchTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	TrenchCoat currentTrench = this->basket[row];
	int column = index.column();
	if (role == Qt::DisplayRole || role == Qt::EditRole) 
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(to_string(currentTrench.getSize()));
		case 1:
			return QString::fromStdString(currentTrench.getColour());
		case 2:
			return QString::fromStdString(to_string(currentTrench.getPrice()));
		case 3:
			return QString::fromStdString(to_string(currentTrench.getQuantity()));
		case 4:
			return QString::fromStdString(currentTrench.getPhotoLink());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant TrenchTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return QString("Size");
			case 1:
				return QString("Colour");
			case 2:
				return QString("Price");
			case 3:
				return QString("Quantity");
			case 4:
				return QString("Photo link");
			default:
				break;
			}
		}
	}
	return QVariant();
}

void TrenchTableModel::update()
{
	QModelIndex topLeft = this->index(1, 1);
	QModelIndex bottomRight = this->index(this->rowCount(), this->columnCount());
	emit layoutChanged();
	emit dataChanged(topLeft, bottomRight);
}
