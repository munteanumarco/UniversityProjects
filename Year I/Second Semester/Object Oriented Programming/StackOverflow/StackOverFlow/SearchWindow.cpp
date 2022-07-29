#include "SearchWindow.h"
#include <algorithm>
SearchWindow::SearchWindow(Controller cont, QWidget* parent)
	: cont(cont), QWidget(parent)
{

	this->initGUI();
	this->connectSignals();
}

void SearchWindow::initGUI()
{
	this->setWindowTitle("Search");
	mainLayout = new QVBoxLayout(this);
	searchFormLayout = new QFormLayout(this);
	searchLabel = new QLabel("Search:", this);
	searchLineEdit = new QLineEdit(this);
	searchFormLayout->addRow(searchLabel, searchLineEdit);

	mainLayout->addItem(searchFormLayout);
	searchResultListWidget = new QListWidget(this);
	mainLayout->addWidget(searchResultListWidget);
}

void SearchWindow::connectSignals()
{
	QObject::connect(searchLineEdit, &QLineEdit::textChanged, this, &SearchWindow::handleTextChanged);
}

void SearchWindow::update()
{
}

void SearchWindow::handleTextChanged()
{
	this->searchResultListWidget->clear();
	string text = this->searchLineEdit->text().toStdString();
	Question q = this->cont.getMatchingQuestion(text);
	vector<Answer> answers = this->cont.getAnswersForQuestion(q);
	sort(answers.begin(), answers.end(), [](Answer a1, Answer a2) {
		return a1.getVotes() > a2.getVotes();
		});
	QListWidgetItem* labelQuestion = new QListWidgetItem("Question :");
	QListWidgetItem* labelAnswers= new QListWidgetItem("Answers :");
	QListWidgetItem* question = new QListWidgetItem(q.toString().c_str());
	this->searchResultListWidget->addItem(labelQuestion);
	this->searchResultListWidget->addItem(question);
	this->searchResultListWidget->addItem(labelAnswers);
	int size = answers.size();
	if (size > 3)
	{
		size = 3;
	}
	for (int i = 0; i < size; i++)
	{
		QListWidgetItem* item = new QListWidgetItem(answers[i].toString().c_str());
		this->searchResultListWidget->addItem(item);
	}
}
