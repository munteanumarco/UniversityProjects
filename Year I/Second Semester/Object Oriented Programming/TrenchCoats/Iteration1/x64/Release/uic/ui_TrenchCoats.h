/********************************************************************************
** Form generated from reading UI file 'TrenchCoats.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRENCHCOATS_H
#define UI_TRENCHCOATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrenchCoatsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrenchCoatsClass)
    {
        if (TrenchCoatsClass->objectName().isEmpty())
            TrenchCoatsClass->setObjectName(QString::fromUtf8("TrenchCoatsClass"));
        TrenchCoatsClass->resize(600, 400);
        menuBar = new QMenuBar(TrenchCoatsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TrenchCoatsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrenchCoatsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TrenchCoatsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TrenchCoatsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TrenchCoatsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TrenchCoatsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TrenchCoatsClass->setStatusBar(statusBar);

        retranslateUi(TrenchCoatsClass);

        QMetaObject::connectSlotsByName(TrenchCoatsClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrenchCoatsClass)
    {
        TrenchCoatsClass->setWindowTitle(QCoreApplication::translate("TrenchCoatsClass", "TrenchCoats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrenchCoatsClass: public Ui_TrenchCoatsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRENCHCOATS_H
