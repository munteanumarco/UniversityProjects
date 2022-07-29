#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TrenchCoats.h"
#include "trench_controller.h"
class TrenchCoats : public QMainWindow
{
    Q_OBJECT

public:
    TrenchCoats(TrenchController cont, QWidget *parent = Q_NULLPTR);
private:
    Ui::TrenchCoatsClass ui;
    TrenchController cont;
private slots:
    void handleDisplay();
    void handleShowInternalBasket();
    void handleStartUser();
    void handleAddTrench();
    void handleDeleteTrench();
    void handleUpdateTrench();
    void handleDisplayDeleted();
    void handleFilter();
    void handleSeeImage();
    void handleAddToBasket();
    void handleShowBasket();
    void handleUndo();
    void handleRedo();
    void handleShowTable();
};
