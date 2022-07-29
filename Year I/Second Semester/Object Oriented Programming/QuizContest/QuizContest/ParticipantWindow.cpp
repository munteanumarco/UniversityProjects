#include "ParticipantWindow.h"

ParticipantWindow::ParticipantWindow(RepoQuestions& repoQ, RepoParticipants& repoP, Participant& p, QWidget* parent)
	: repoQuestions(repoQ), repoParticipants(repoP), p(p), QWidget(parent)
{
	this->repoQuestions.addObserver(this);
	this->initGUI();
	this->connectSignals();
	this->show();
}

ParticipantWindow::~ParticipantWindow()
{
}

void ParticipantWindow::update()
{
    this->notifyModel();
}

void ParticipantWindow::notifyModel()
{
    this->tableModel->updateInternalData();
}

void ParticipantWindow::initGUI()
{
    QFont buttonsFont("Consolas", 13, true);

    this->questionsTableView = new QTableView();
    this->tableModel = new TableModel(this->repoQuestions);

    this->questionsTableView->setModel(this->tableModel);

    this->questionsTableView->resizeColumnsToContents();

    this->answerLineEdit = new QLineEdit();
    this->answerLineEdit->setFont(buttonsFont);

    this->answerLabel = new QLabel("Answer");
    this->answerLabel->setFont(buttonsFont);

    this->answerButton = new QPushButton("Answer the question");
    this->answerButton->setFont(buttonsFont);

    QLabel* score = new QLabel("Score: ");
    score->setFont(buttonsFont);

    this->scoreLabel = new QLabel();
    this->scoreLabel->setText(QString::fromStdString(to_string(this->p.getScore())));
    this->scoreLabel->setFont(buttonsFont);

    this->buttonsLayout = new QGridLayout();
    this->mainLayout = new QVBoxLayout();

    this->mainLayout->addWidget(this->questionsTableView);
    this->buttonsLayout->addWidget(this->answerLabel, 0, 0);
    this->buttonsLayout->addWidget(this->answerLineEdit, 0, 1);
    this->buttonsLayout->addWidget(this->answerButton, 0, 2);
    this->buttonsLayout->addWidget(score, 1, 0);
    this->buttonsLayout->addWidget(this->scoreLabel, 1, 1);

    this->mainLayout->addLayout(this->buttonsLayout);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->p.getName()));
    this->resize(1200, 700);
}

void ParticipantWindow::connectSignals()
{
    QObject::connect(this->questionsTableView, &QTableView::clicked, this, &ParticipantWindow::checkIfAnswered);
    QObject::connect(this->answerButton, &QPushButton::clicked, this, &ParticipantWindow::answerQuestion);
}

void ParticipantWindow::answerQuestion()
{
    string answer = this->answerLineEdit->text().toStdString();
    Question q = this->repoQuestions.getQuestions()[this->questionsTableView->currentIndex().row()];
    try
    {
        this->repoParticipants.updateParticipantScore(q, answer, this->p);
        this->tableModel->addBackground(this->questionsTableView->currentIndex().row());
        QMessageBox::information(this, "Correct answer !", "Correct answer !", QMessageBox::Ok);
        this->scoreLabel->setText(QString::fromStdString(to_string(this->p.getScore())));
        this->answerLineEdit->clear();
        return;
    }
    catch (...)
    {
        this->answerLineEdit->clear();
        QMessageBox::information(this, "Wrong answer!", "Wrong answer!", QMessageBox::Ok);
        return;
    }
}

void ParticipantWindow::checkIfAnswered(const QModelIndex& index)
{
    auto color = this->tableModel->data(index, Qt::BackgroundRole);
    if (color == QBrush(QColor(Qt::green)))
    {
        this->answerButton->setDisabled(true);
    }
    else
    {
        this->answerButton->setEnabled(true);
    }
}
