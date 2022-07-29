#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Waze.h"

class Waze : public QMainWindow
{
    Q_OBJECT

public:
    Waze(QWidget *parent = Q_NULLPTR);

private:
    Ui::WazeClass ui;
};
