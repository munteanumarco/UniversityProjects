#include "WriterWindow.h"
#include <fstream>
WriterWindow::WriterWindow(TableModel* model, Writer &w, QWidget *parent)
	: model(model), w(w), QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(w.getName().c_str());
	this->ui.tableView->setModel(model);
	if (this->w.getExpertise() != "Senior")
	{
		this->ui.acceptButton->setDisabled(true);
	}
}

WriterWindow::~WriterWindow()
{
}

void WriterWindow::handleAccept()
{
	int index = this->getSelectedIndex();
	if (index == -1)
	{
		QMessageBox::information(this, "Error", "No selected items", QMessageBox::Ok);
	}
	else
	{
		this->model->acceptIdea(index);
	}
}
void WriterWindow::handleDevelop()
{
	/*QLayoutItem* item;
	while ((item = developLayout->takeAt(0)) != 0)
	{
		delete item;
	}*/
	for (Idea i : this->model->getIdeas())
	{
		if (i.getCreator() == this->w.getName() && i.getStatus() == "accepted")
		{
			QHBoxLayout* hLayout = new QHBoxLayout();
			QTextEdit* textEdit = new QTextEdit;
			textEdit->setText(QString::fromStdString(i.getDescription()));
			this->textEdits.push_back(textEdit);
			QPushButton* saveButton = new QPushButton("Save");
			string name = this->w.getName();
			QObject::connect(saveButton, &QPushButton::clicked, this, [name, textEdit]() {
				string s = "develop" + name + ".txt";
				ofstream file;
				file.open(s);
				if (file.is_open())
				{
					string description = textEdit->toPlainText().toStdString();
					file << description;
					file.close();
				}
				});
			this->saveButtons.push_back(saveButton);
			hLayout->addWidget(textEdit);
			hLayout->addWidget(saveButton);
			this->ui.verticalLayout->addLayout(hLayout);
		}
	}
}
int WriterWindow::getSelectedIndex()
{
	auto indexes = this->ui.tableView->selectionModel()->selectedIndexes();
	if (indexes.isEmpty())
	{
		return -1;
	}
	return indexes.at(0).row();
}
void WriterWindow::handleAdd()
{
	string description = this->ui.descriptionLineEdit->text().toStdString();
	string sact = this->ui.actLineEdit->text().toStdString();
	if (description.size() > 0 && sact.size() > 0)
	{
		int act = stoi(sact);
		Idea i(description, "proposed", this->w.getName(), act);
		try
		{
			this->model->addIdea(i);
			this->ui.actLineEdit->clear();
			this->ui.descriptionLineEdit->clear();
			QMessageBox::information(this, "Success", "Added new idea", QMessageBox::Ok);
		}
		catch (exception& ex)
		{
			QMessageBox::information(this, "Error", ex.what(), QMessageBox::Ok);
		}
	}
	else
	{
		QMessageBox::information(this, "Error", "Empty Fields", QMessageBox::Ok);
	}
}
