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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/qgridlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/qstackedwidget.h>
#include <QtWidgets/qcombobox.h>
#include <qshortcut.h>

QT_BEGIN_NAMESPACE

class Ui_TrenchCoatsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* displayButton;
    QPushButton* displayDeletedButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *sizeLabel;
    QComboBox* sizeComboBox;
    QLabel* colourLabel;
    QLineEdit* colourLineEdit;
    QLabel* priceLabel;
    QLineEdit* priceLineEdit;
    QLabel* quantityLabel;
    QLineEdit* quantityLineEdit;
    QLabel* linkLabel;
    QLineEdit* linkLineEdit;
    QFormLayout* inputForm;
    QWidget *gridLayoutWidget;
    QGridLayout* gridLayout;
    QLineEdit* filterLineEdit;
    QListWidget *coatsList;
    QLabel* coatsLabel;
    QWidget* verticalBasketLayoutWidget;
    QVBoxLayout* verticalBasketLayout;
    QWidget* gridButtonsLayoutWidget;
    QGridLayout* gridButtonsLayout;
    QWidget* gridStartButtonsLayoutWidget;
    QGridLayout* gridStartButtonsLayout;
    QListWidget* shoppingBasketList;
    QPushButton* showBasketButton;
    QLabel* currentItemLabel;
    QPushButton* seeImageButton;
    QPushButton* addToBasketButton;
    QComboBox* sizeUserBox;
    QPushButton* showExternalBasketButton;
    QStackedWidget* userButtonsStackedWidget;
    QPushButton* startUserButton;
    QComboBox* savingOptionBox;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QPushButton* showTableButton;

    void setupUi(QMainWindow *TrenchCoatsClass)
    {
        if (TrenchCoatsClass->objectName().isEmpty())
            TrenchCoatsClass->setObjectName(QString::fromUtf8("TrenchCoatsClass"));
        TrenchCoatsClass->resize(600, 700);
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

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setGeometry(10, 10, 200, 250);
        
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);

        coatsList = new QListWidget(verticalLayoutWidget);
      

        coatsLabel = new QLabel(verticalLayoutWidget);
        coatsLabel->setText("All Trench Coats :");

        QWidget* formWidget = new QWidget(centralWidget);
        formWidget->setGeometry(10, 280, 200, 300);

        inputForm = new QFormLayout(formWidget);

        sizeComboBox = new QComboBox;
        sizeComboBox->addItem("XS");
        sizeComboBox->addItem("S");
        sizeComboBox->addItem("M");
        sizeComboBox->addItem("L");
        sizeComboBox->addItem("XL");
        sizeComboBox->addItem("XLL");

        inputForm->addRow("Size : ", sizeComboBox);
        colourLineEdit = new QLineEdit;
        inputForm->addRow("Colour : ", colourLineEdit);
        priceLineEdit = new QLineEdit;
        inputForm->addRow("Price : ", priceLineEdit);
        quantityLineEdit = new QLineEdit;
        inputForm->addRow("Quantity : ", quantityLineEdit);
        linkLineEdit = new QLineEdit;
        inputForm->addRow("Link : ", linkLineEdit);

        filterLineEdit = new QLineEdit;

        verticalLayout->addWidget(filterLineEdit);
        verticalLayout->addWidget(coatsLabel);
        verticalLayout->addWidget(coatsList);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setGeometry(10, 450, 250, 200);


        gridLayout = new QGridLayout(gridLayoutWidget);

        addButton = new QPushButton(gridLayoutWidget);
        addButton->setText("Add");
        gridLayout->addWidget(addButton, 0, 0);


        deleteButton = new QPushButton(gridLayoutWidget);
        deleteButton->setText("Delete");
        gridLayout->addWidget(deleteButton,0,1);

        updateButton = new QPushButton(gridLayoutWidget);
        updateButton->setText("Update");
        gridLayout->addWidget(updateButton,0,2);


        QLinearGradient linearGradient(0,0,100,100);
        linearGradient.setColorAt(0, QColor(100, 120, 140));
        linearGradient.setColorAt(0.5, QColor(90, 20, 40));
        linearGradient.setColorAt(1, QColor(160, 180, 200));

        QPalette palette = qApp->palette();
        palette.setBrush(QPalette::Base, linearGradient);
        palette.setBrush(QPalette::Highlight, linearGradient);
        palette.setBrush(QPalette::HighlightedText, Qt::white);
        palette.setBrush(QPalette::Text, Qt::white);

        displayButton = new QPushButton(gridLayoutWidget);
        displayButton->setText("Display");
        gridLayout->addWidget(displayButton, 1, 0, 1, 3);

        displayButton->setPalette(palette);

        
        displayDeletedButton = new QPushButton("Display deleted", gridLayoutWidget);
        gridLayout->addWidget(displayDeletedButton,2,0,1,3);

        undoButton = new QPushButton("Undo", gridLayoutWidget);
        gridLayout->addWidget(undoButton,3,0,1,1);

        redoButton = new QPushButton("Redo", gridLayoutWidget);
        gridLayout->addWidget(redoButton, 3, 2, 1, 1);

        verticalBasketLayoutWidget = new QWidget(centralWidget);
        verticalBasketLayoutWidget->setGeometry(310, 10, 250, 400);
        verticalBasketLayout = new QVBoxLayout(verticalBasketLayoutWidget);

        
        shoppingBasketList = new QListWidget(verticalBasketLayoutWidget);
        showBasketButton = new QPushButton("Show Shopping Basket");

        shoppingBasketList->setPalette(palette);
    

        gridButtonsLayoutWidget = new QWidget(verticalBasketLayoutWidget);
        gridButtonsLayout = new QGridLayout(gridButtonsLayoutWidget);
        
        seeImageButton = new QPushButton("See image", gridButtonsLayoutWidget);
        addToBasketButton = new QPushButton("Add to basket", gridButtonsLayoutWidget);
        showExternalBasketButton = new QPushButton("Basket", gridButtonsLayoutWidget);
        showTableButton = new QPushButton("Show Table View", gridLayoutWidget);
     
        sizeUserBox = new QComboBox;
        sizeUserBox->addItem("XS");
        sizeUserBox->addItem("S");
        sizeUserBox->addItem("M");
        sizeUserBox->addItem("L");
        sizeUserBox->addItem("XL");
        sizeUserBox->addItem("XLL");

        gridButtonsLayout->addWidget(shoppingBasketList, 0, 0, 1, 2);
        gridButtonsLayout->addWidget(seeImageButton,2,0);
        gridButtonsLayout->addWidget(addToBasketButton,2,1);
        gridButtonsLayout->addWidget(showExternalBasketButton,3,0,1,2);
        gridButtonsLayout->addWidget(showTableButton, 4, 0, 1, 2);
        gridButtonsLayout->addWidget(sizeUserBox,1,0,1,2);
        

        gridStartButtonsLayoutWidget = new  QWidget(centralWidget);
        gridStartButtonsLayoutWidget->setGeometry(10, 450, 200, 100);

        gridStartButtonsLayout = new QGridLayout(gridStartButtonsLayoutWidget);

        startUserButton = new QPushButton("Start", gridStartButtonsLayoutWidget);
        savingOptionBox = new QComboBox;
        savingOptionBox->addItem("CSV");
        savingOptionBox->addItem("HTML");
        
        gridStartButtonsLayout->addWidget(savingOptionBox);
        gridStartButtonsLayout->addWidget(startUserButton);

        userButtonsStackedWidget = new QStackedWidget(verticalBasketLayoutWidget);

        userButtonsStackedWidget->addWidget(gridStartButtonsLayoutWidget);
        userButtonsStackedWidget->addWidget(gridButtonsLayoutWidget);      
      
        verticalBasketLayout->addWidget(userButtonsStackedWidget);
       

        retranslateUi(TrenchCoatsClass);

        QObject::connect(displayButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleDisplay()));
        QObject::connect(showBasketButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleShowInternalBasket()));
        QObject::connect(startUserButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleStartUser()));
        QObject::connect(addButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleAddTrench()));
        QObject::connect(deleteButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleDeleteTrench()));
        QObject::connect(updateButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleUpdateTrench()));
        QObject::connect(displayDeletedButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleDisplayDeleted()));
        QObject::connect(filterLineEdit, SIGNAL(textChanged(QString)), TrenchCoatsClass, SLOT(handleFilter()));
        QObject::connect(sizeUserBox, SIGNAL(currentIndexChanged(int)), TrenchCoatsClass, SLOT(handleStartUser()));
        QObject::connect(seeImageButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleSeeImage()));
        QObject::connect(addToBasketButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleAddToBasket()));
        QObject::connect(showExternalBasketButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleShowBasket()));
        QObject::connect(undoButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleUndo()));
        QObject::connect(redoButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleRedo()));
        QShortcut* undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), TrenchCoatsClass);
        QObject::connect(undoShortcut, SIGNAL(activated()), TrenchCoatsClass, SLOT(handleUndo()));
        QShortcut* redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), TrenchCoatsClass);
        QObject::connect(redoShortcut, SIGNAL(activated()), TrenchCoatsClass, SLOT(handleRedo()));
        QObject::connect(showTableButton, SIGNAL(clicked()), TrenchCoatsClass, SLOT(handleShowTable()));

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
