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
        if (QuizContestClass->objectName().isEmpty())
            QuizContestClass->setObjectName(QString::fromUtf8("QuizContestClass"));
        QuizContestClass->resize(600, 400);
        menuBar = new QMenuBar(QuizContestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QuizContestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuizContestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QuizContestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QuizContestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QuizContestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QuizContestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QuizContestClass->setStatusBar(statusBar);

        retranslateUi(QuizContestClass);

        QMetaObject::connectSlotsByName(QuizContestClass);
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
