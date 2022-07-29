#pragma once
#include "repo_questions.h"
#include "repo_participants.h"
#include <QWidget>
#include <QPushButton>
#include "observer.h"
#include <QTableView>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include "TabelModel.h"
#include <qmessagebox.h>

class ParticipantWindow : public QWidget, public Observer {
private:
	RepoQuestions& repoQuestions;
	RepoParticipants& repoParticipants;
	Participant& p;
	TableModel* tableModel;
	QTableView* questionsTableView;
	QLineEdit* answerLineEdit;
	QPushButton* answerButton;
	QLabel* answerLabel;
	QVBoxLayout* mainLayout;
	QGridLayout* buttonsLayout;
	QLabel* scoreLabel;

public:
	ParticipantWindow(RepoQuestions& repoQ, RepoParticipants& repoP, Participant& p, QWidget* parent = Q_NULLPTR);
	~ParticipantWindow();
	void update() override;
	void notifyModel();
	void initGUI();
	void connectSignals();
	void answerQuestion();
	void checkIfAnswered(const QModelIndex& index);

};