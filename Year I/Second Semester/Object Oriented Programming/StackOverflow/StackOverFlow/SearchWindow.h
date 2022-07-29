#pragma once
#include <qwidget.h>
#include "Observer.h"
#include "cont.h"
#include "qlayout.h"
#include "qlineedit.h"
#include "qformlayout.h"
#include "qlabel.h"
#include "qlistwidget.h"
#include "qpushbutton.h"
#include "qmessagebox.h"
#include "qspinbox.h"
class SearchWindow : public QWidget, public Observer {
private:
	Controller cont;
public:
	SearchWindow(Controller cont, QWidget *parent);
private:
	QVBoxLayout* mainLayout;
	QFormLayout* searchFormLayout;
	QLabel* searchLabel;
	QLineEdit* searchLineEdit;
	QListWidget* searchResultListWidget;
	void initGUI();
	void connectSignals();
public:
	void update() override;
private slots:
	void handleTextChanged();
	
};