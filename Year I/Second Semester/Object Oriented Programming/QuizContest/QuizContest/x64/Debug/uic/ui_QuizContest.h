/********************************************************************************
** Form generated from reading UI file 'QuizContest.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZCONTEST_H
#define UI_QUIZCONTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "repo_questions.h"
#include "repo_participants.h"
#include "ParticipantWindow.h"
#include "PresenterWindow.h"
QT_BEGIN_NAMESPACE

class Ui_QuizContestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuizContestClass)
    {

    } // setupUi

    void retranslateUi(QMainWindow *QuizContestClass)
    {
        QuizContestClass->setWindowTitle(QCoreApplication::translate("QuizContestClass", "QuizContest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuizContestClass: public Ui_QuizContestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZCONTEST_H
