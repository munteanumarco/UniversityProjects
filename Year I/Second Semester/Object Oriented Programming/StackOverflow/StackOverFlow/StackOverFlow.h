#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StackOverFlow.h"

class StackOverFlow : public QMainWindow
{
    Q_OBJECT

public:
    StackOverFlow(QWidget *parent = Q_NULLPTR);

private:
    Ui::StackOverFlowClass ui;
};
