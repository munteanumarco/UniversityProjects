#pragma once

#include <QWidget>
#include "ui_WriterWindow.h"
#include "Cont.h"
#include "TableModel.h"
#include "qmessagebox.h"
#include <vector>
class WriterWindow : public QWidget
{
	Q_OBJECT

public:
	WriterWindow(TableModel* model, Writer& w,QWidget *parent = Q_NULLPTR);
	~WriterWindow();

private:
	Ui::WriterWindow ui;
	TableModel* model;
	Writer& w;
	vector<QTextEdit*> textEdits;
	vector<QPushButton*> saveButtons;
private slots:
	int getSelectedIndex();
	void handleAdd();
	void handleAccept();
	void handleDevelop();
};
