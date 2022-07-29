#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManager.h"

class TaskManager : public QMainWindow
{
    Q_OBJECT

public:
    TaskManager(QWidget *parent = Q_NULLPTR);

private:
    Ui::TaskManagerClass ui;
};
