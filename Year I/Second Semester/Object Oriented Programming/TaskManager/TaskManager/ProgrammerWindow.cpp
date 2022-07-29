#include "ProgrammerWindow.h"
#include <sstream>
#include "utils.h"
ProgrammerWindow::ProgrammerWindow(Controller cont, Programmer& p, QWidget* parent)
	: cont(cont), p(p), QWidget(parent)
{
	this->setWindowTitle(QString::fromStdString(p.getName()));
	this->cont.addObserver(this);
	this->initGUI();
	this->connectSignals();
}

void ProgrammerWindow::initGUI()
{
	
	auto mainLayout = new QVBoxLayout(this);

	tasksListWidget = new QListWidget(this);
	mainLayout->addWidget(tasksListWidget);

	auto buttonsLayout = new QGridLayout(this);
	addButton = new QPushButton("Add", this);
	deleteButton = new QPushButton("Delete", this);
	startButton = new QPushButton("Start", this);
	doneButton = new QPushButton("Done", this);
	doneButton->setDisabled(true);
	inputFormLayout = new QFormLayout(this);
	descriptionLabel = new QLabel(this);
	descriptionLabel->setText("Description:");
	descriptionLineEdit = new QLineEdit(this);

	inputFormLayout->addRow(descriptionLabel, descriptionLineEdit);

	mainLayout->addItem(inputFormLayout);

	buttonsLayout->addWidget(addButton, 0, 0);
	buttonsLayout->addWidget(deleteButton, 0, 1);
	buttonsLayout->addWidget(startButton, 1, 0);
	buttonsLayout->addWidget(doneButton, 1, 1);

	mainLayout->addItem(buttonsLayout);

	this->update();
}

void ProgrammerWindow::connectSignals()
{
	QObject::connect(startButton, &QPushButton::clicked, this, &ProgrammerWindow::handleStart);
	QObject::connect(doneButton, &QPushButton::clicked, this, &ProgrammerWindow::handleDone);
	QObject::connect(addButton, &QPushButton::clicked, this, &ProgrammerWindow::handleAdd);
	QObject::connect(deleteButton, &QPushButton::clicked, this, &ProgrammerWindow::handleDelete);
	QObject::connect(tasksListWidget, &QListWidget::itemSelectionChanged, this, &ProgrammerWindow::handleDoneButton);
}

void ProgrammerWindow::handleAdd()
{
	string description = this->descriptionLineEdit->text().toStdString();
	if (description.size() > 0)
	{
		Task t(description, "open", this->p.getId());
		try
		{
			this->cont.addTask(t);
			QMessageBox::information(this, "Success", "Success", QMessageBox::Ok);
		}
		catch (...)
		{
			QMessageBox::information(this, "Error", "Error", QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "Error", "Error", QMessageBox::Ok);
	}
}

void ProgrammerWindow::handleDelete()
{
	
	auto text = this->tasksListWidget->currentItem()->text().toStdString();

	stringstream ss{ text };
	Task t;
	ss >> t;
	try
	{
		this->cont.removeTask(t);
		QMessageBox::information(this, "Success", "Success", QMessageBox::Ok);
	}
	catch (...)
	{
		QMessageBox::information(this, "Error", "Error", QMessageBox::Ok);
	}
	
}

void ProgrammerWindow::handleStart()
{
	auto text = this->tasksListWidget->currentItem()->text().toStdString();
	stringstream ss{ text };
	Task t;
	ss >> t;
	if (t.getStatus() == "open")
	{
		this->cont.updateTaskStatus(t, "in progress", this->p.getId());
		QMessageBox::information(this, "Success", "Keep up the work!", QMessageBox::Ok);
	}
	else
	{
		QMessageBox::information(this, "Error", "Task not open !", QMessageBox::Ok);
	}
}

void ProgrammerWindow::handleDone()
{
	auto text = this->tasksListWidget->currentItem()->text().toStdString();
	vector<string> tokens = tokenize(text, '-');
	stringstream ss{tokens[0]};
	Task t;
	ss >> t;
	int id = t.getId();
	this->cont.updateTaskStatus(t, "closed", id);
}

void ProgrammerWindow::handleDoneButton()
{
	try
	{
		auto text = this->tasksListWidget->currentItem()->text().toStdString();
		stringstream ss{ text };
		Task t;
		ss >> t;
		if ((t.getStatus() == "in progress") && (t.getId() == this->p.getId()))
		{
			this->doneButton->setDisabled(false);
		}
		else
		{
			this->doneButton->setDisabled(true);
		}
	}
	catch (...)
	{

	}
}

void ProgrammerWindow::update()
{
	this->updateTaskList();
}

void ProgrammerWindow::updateTaskList()
{
	this->tasksListWidget->clear();
	for (auto t : this->cont.getTasks())
	{
		string s = t.toString();
		if (t.getId() != 0)
		{
			Programmer currentProgrammer = this->cont.getProgrammerById(t.getId());
			if (t.getStatus() == "in progress")
			{
				s = s + "-" + currentProgrammer.getName();
			}
		}
		auto item = new QListWidgetItem(s.c_str());
		tasksListWidget->addItem(item);
	}
}
