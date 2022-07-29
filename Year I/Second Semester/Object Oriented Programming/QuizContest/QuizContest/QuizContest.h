#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QuizContest.h"

class QuizContest : public QMainWindow
{
    Q_OBJECT

public:
    QuizContest(QWidget *parent = Q_NULLPTR);

private:
    Ui::QuizContestClass ui;
};
