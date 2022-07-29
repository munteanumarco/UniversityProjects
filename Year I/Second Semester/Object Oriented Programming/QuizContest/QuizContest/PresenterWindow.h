#pragma once
#include "repo_questions.h"
#include <QWidget>
#include "Observer.h"
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include "TableModelPresenter.h"
#include <QTableView>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QMessageBox>

class PresenterWindow : public QWidget, public Observer {
private:
	RepoQuestions& repo;
    QLineEdit* idLineEdit, * textLineEdit, * correctAnswerLineEdit;
    QPushButton* addButton;
    QTableView* questionsTableView;
    TableModelPresenter* tableModel;
    QLabel* idLabel, * textLabel, * correctAnswerLabel;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QSortFilterProxyModel* filterModel;
public:
    PresenterWindow(RepoQuestions& repo, QWidget* parent = Q_NULLPTR);
    ~PresenterWindow();
    void update() override;
    void notifyModel();
    void initGUI();
    void connectSignals();
    void addQuestion();
};