/********************************************************************************
** Form generated from reading UI file 'WriterWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITERWINDOW_H
#define UI_WRITERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WriterWindow
{
public:
    QTableView *tableView;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *descriptionLineEdit;
    QLabel *label_2;
    QLineEdit *actLineEdit;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *acceptButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *developButton;
    QPushButton *saveButton;
    QPushButton *savePlotButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *WriterWindow)
    {
        if (WriterWindow->objectName().isEmpty())
            WriterWindow->setObjectName(QString::fromUtf8("WriterWindow"));
        WriterWindow->resize(852, 464);
        tableView = new QTableView(WriterWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 20, 411, 121));
        formLayoutWidget = new QWidget(WriterWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 180, 191, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        descriptionLineEdit = new QLineEdit(formLayoutWidget);
        descriptionLineEdit->setObjectName(QString::fromUtf8("descriptionLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, descriptionLineEdit);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        actLineEdit = new QLineEdit(formLayoutWidget);
        actLineEdit->setObjectName(QString::fromUtf8("actLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, actLineEdit);

        textEdit = new QTextEdit(WriterWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(470, 50, 311, 71));
        horizontalLayoutWidget = new QWidget(WriterWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 250, 239, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        acceptButton = new QPushButton(horizontalLayoutWidget);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        horizontalLayout->addWidget(acceptButton);

        horizontalLayoutWidget_2 = new QWidget(WriterWindow);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(470, 140, 160, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        developButton = new QPushButton(horizontalLayoutWidget_2);
        developButton->setObjectName(QString::fromUtf8("developButton"));

        horizontalLayout_2->addWidget(developButton);

        saveButton = new QPushButton(horizontalLayoutWidget_2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_2->addWidget(saveButton);

        savePlotButton = new QPushButton(WriterWindow);
        savePlotButton->setObjectName(QString::fromUtf8("savePlotButton"));
        savePlotButton->setGeometry(QRect(530, 250, 75, 24));
        verticalLayoutWidget = new QWidget(WriterWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(430, 290, 281, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(WriterWindow);
        QObject::connect(addButton, SIGNAL(clicked()), WriterWindow, SLOT(handleAdd()));
        QObject::connect(acceptButton, SIGNAL(clicked()), WriterWindow, SLOT(handleAccept()));
        QObject::connect(saveButton, SIGNAL(clicked()), WriterWindow, SLOT(handleSave()));
        QObject::connect(developButton, SIGNAL(clicked()), WriterWindow, SLOT(handleDevelop()));
        QObject::connect(savePlotButton, SIGNAL(clicked()), WriterWindow, SLOT(handleSavePlot()));

        QMetaObject::connectSlotsByName(WriterWindow);
    } // setupUi

    void retranslateUi(QWidget *WriterWindow)
    {
        WriterWindow->setWindowTitle(QCoreApplication::translate("WriterWindow", "WriterWindow", nullptr));
        label->setText(QCoreApplication::translate("WriterWindow", "Description:", nullptr));
        label_2->setText(QCoreApplication::translate("WriterWindow", "Act:", nullptr));
        addButton->setText(QCoreApplication::translate("WriterWindow", "Add", nullptr));
        acceptButton->setText(QCoreApplication::translate("WriterWindow", "Accept", nullptr));
        developButton->setText(QCoreApplication::translate("WriterWindow", "Develop", nullptr));
        saveButton->setText(QCoreApplication::translate("WriterWindow", "Save", nullptr));
        savePlotButton->setText(QCoreApplication::translate("WriterWindow", "Save Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WriterWindow: public Ui_WriterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITERWINDOW_H
