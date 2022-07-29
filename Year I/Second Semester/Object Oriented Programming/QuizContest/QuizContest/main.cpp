#include "QuizContest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuizContest w;
    w.show();
    RepoQuestions repoQ;
    RepoParticipants repoP;
    vector<ParticipantWindow*> windows;
    for (auto p : repoP.getParticipants())
    {
        windows.push_back(new ParticipantWindow(repoQ, repoP, p));
    }

    PresenterWindow presenterWindow(repoQ);
    return a.exec();
}
