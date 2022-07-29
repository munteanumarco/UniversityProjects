/********************************************************************************
** Form generated from reading UI file 'StackOverFlow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKOVERFLOW_H
#define UI_STACKOVERFLOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StackOverFlowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StackOverFlowClass)
    {
        if (StackOverFlowClass->objectName().isEmpty())
            StackOverFlowClass->setObjectName(QString::fromUtf8("StackOverFlowClass"));
        StackOverFlowClass->resize(600, 400);
        menuBar = new QMenuBar(StackOverFlowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        StackOverFlowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StackOverFlowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        StackOverFlowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(StackOverFlowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        StackOverFlowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(StackOverFlowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        StackOverFlowClass->setStatusBar(statusBar);

        retranslateUi(StackOverFlowClass);

        QMetaObject::connectSlotsByName(StackOverFlowClass);
    } // setupUi

    void retranslateUi(QMainWindow *StackOverFlowClass)
    {
        StackOverFlowClass->setWindowTitle(QCoreApplication::translate("StackOverFlowClass", "StackOverFlow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StackOverFlowClass: public Ui_StackOverFlowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKOVERFLOW_H
