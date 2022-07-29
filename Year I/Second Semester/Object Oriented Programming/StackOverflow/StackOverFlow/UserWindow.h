#pragma once
#include <QWidget>
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

class UserWindow : public Observer, public QWidget {
private:
	Controller cont;
	User u;
public:
	UserWindow(Controller cont, User& u, QWidget* parent);
private:
	QVBoxLayout* mainLayout;
	QListWidget* questionsListWidget;
	QListWidget* answersListWidget;
	QPushButton* addButton;
	QPushButton* answerButton;
	QFormLayout* inputFormLayout;
	QFormLayout* answerFormLayout;
	QLabel* textAnswerLabel;
	QLineEdit* textAnswerLineEdit;
	QLineEdit* idAnswerLineEdit;
	QLabel* idAnswerLabel;
	QLabel* idLabel;
	QLabel* textLabel;
	QLineEdit* idLineEdit;
	QLineEdit* textLineEdit;
	QSpinBox* userSpinBox;
	Answer lastSelectedAnswer;
	void initGUI();
	void connectSignals();
public:
	void update() override;
private:
	void updateQuestionList();
private slots:
	void handleAdd();
	void handleShowAnswers();
	void handleAnswer();
	void handleSpinBox();
	void handleSpinBoxUpdate();
};