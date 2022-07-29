#pragma once
#include <QAbstractTableModel>
#include "repo_questions.h"

class TableModel : public QAbstractTableModel {

private:
    RepoQuestions& repository;
    vector<int> indexes;

public:

    TableModel(RepoQuestions& repository, QObject* parent = NULL);

    ~TableModel();


    int rowCount(const QModelIndex& parent = QModelIndex{}) const override;


    int columnCount(const QModelIndex& parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;


    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    void addBackground(int idx);

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void updateInternalData();
};

