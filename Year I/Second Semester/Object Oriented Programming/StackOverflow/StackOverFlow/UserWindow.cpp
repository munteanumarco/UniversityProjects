#include "UserWindow.h"
#include <sstream>
UserWindow::UserWindow(Controller cont, User& u, QWidget* parent)
	: cont(cont), u(u), QWidget(parent)
{
	this->cont.addObserver(this);
	this->initGUI();
	this->connectSignals();
}

void UserWindow::initGUI()
{
	this->setWindowTitle(this->u.getName().c_str());

	mainLayout = new QVBoxLayout(this);

	questionsListWidget = new QListWidget(this);
	answersListWidget = new QListWidget(this);

	mainLayout->addWidget(questionsListWidget);
	mainLayout->addWidget(answersListWidget);

	inputFormLayout = new QFormLayout(this);
	idLabel = new QLabel("ID:", this);
	textLabel = new QLabel("Text:", this);
	idLineEdit = new QLineEdit(this);
	textLineEdit = new QLineEdit(this);

	inputFormLayout->addRow(idLabel, idLineEdit);
	inputFormLayout->addRow(textLabel, textLineEdit);

	mainLayout->addItem(inputFormLayout);

	addButton = new QPushButton("Add", this);
	answerButton = new QPushButton("Answer", this);


	mainLayout->addWidget(addButton);

	answerFormLayout = new QFormLayout(this);
	idAnswerLabel = new QLabel("ID:", this);
	textAnswerLabel = new QLabel("Text:", this);
	idAnswerLineEdit = new QLineEdit(this);
	textAnswerLineEdit = new QLineEdit(this);
	answerFormLayout->addRow(idAnswerLabel, idAnswerLineEdit);
	answerFormLayout->addRow(textAnswerLabel, textAnswerLineEdit);

	mainLayout->addItem(answerFormLayout);
	mainLayout->addWidget(answerButton);

	userSpinBox = new QSpinBox(this);
	userSpinBox->setDisabled(true);

	mainLayout->addWidget(userSpinBox);

	this->update();

}

void UserWindow::connectSignals()
{
	QObject::connect(addButton, &QPushButton::clicked, this, &UserWindow::handleAdd);
	QObject::connect(questionsListWidget, &QListWidget::itemSelectionChanged, this, &UserWindow::handleShowAnswers);
	QObject::connect(answerButton, &QPushButton::clicked, this, &UserWindow::handleAnswer);
	QObject::connect(answersListWidget, &QListWidget::itemSelectionChanged, this, &UserWindow::handleSpinBox);
	QObject::connect(userSpinBox, &QSpinBox::valueChanged, this, &UserWindow::handleSpinBoxUpdate);
}

void UserWindow::update()
{
	this->updateQuestionList();
}

void UserWindow::updateQuestionList()
{
	this->questionsListWidget->clear();
	for (Question q : this->cont.getQuestions())
	{
		auto text = q.toString();
		QListWidgetItem *item =  new QListWidgetItem(text.c_str());
		this->questionsListWidget->addItem(item);
	}
}

void UserWindow::handleShowAnswers()
{
	string text = this->questionsListWidget->currentItem()->text().toStdString();
	stringstream s{text};
	Question q;
	s >> q;
	vector<Answer> answers = this->cont.getAnswersForQuestion(q);
	this->answersListWidget->clear();
	for (Answer a : answers)
	{
		auto text = a.toString();
		QListWidgetItem* item = new QListWidgetItem(text.c_str());
		string name = this->u.getName();
		if (a.getName() == this->u.getName())
		{
			item->setBackground(Qt::yellow);
		}
		this->answersListWidget->addItem(item);
	
	}
}

void UserWindow::handleAnswer()
{
	string text = this->textAnswerLineEdit->text().toStdString();
	string id = this->idAnswerLineEdit->text().toStdString();
	if (text.size() > 0 && id.size() > 0)
	{
		int actual_id = stoi(id);
		string obj = this->questionsListWidget->currentItem()->text().toStdString();
		stringstream s{ obj };
		Question q;
		s >> q;
		Answer a{ actual_id, q.getId(),this->u.getName(),text,0 };
		this->cont.addAnswer(a);
		this->textAnswerLineEdit->clear();
		this->idAnswerLineEdit->clear();
	}
	else
	{
		QMessageBox::information(this, "error", "empty fields", QMessageBox::Ok);
	}
}

void UserWindow::handleSpinBox()
{
	string text = this->answersListWidget->currentItem()->text().toStdString();
	stringstream s{ text };
	Answer a;
	s >> a;
	this->lastSelectedAnswer = a;
	if (a.getName() != this->u.getName())
	{
		this->userSpinBox->setDisabled(false);
		this->userSpinBox->setValue(a.getVotes());
	}
	else
	{
		this->userSpinBox->setDisabled(true);
	}
}

void UserWindow::handleSpinBoxUpdate()
{

	int newVotes = this->userSpinBox->value();
	this->cont.updateVotes(this->lastSelectedAnswer, newVotes);
	
}

void UserWindow::handleAdd()
{
	string text = this->textLineEdit->text().toStdString();
	string id = this->idLineEdit->text().toStdString();
	if (text.size() > 0 && id.size() > 0)
	{
		int actual_id = stoi(id);
		Question q(actual_id, text, this->u.getName());
		this->cont.addQuestion(q);
		this->textLineEdit->clear();
		this->idLineEdit->clear();
	}
	else
	{
		QMessageBox::information(this, "error", "Empty fields", QMessageBox::Ok);
	}

}
