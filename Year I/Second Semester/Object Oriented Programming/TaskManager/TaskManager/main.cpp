#include "TaskManager.h"
#include <QtWidgets/QApplication>
#include "repo_programmers.h"
#include "repo_tasks.h"
#include "cont.h"
#include "ProgrammerWindow.h"
#include <vector>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RepoProgrammers repoP;
    RepoTasks repoT;
    Controller cont(repoT, repoP);
    vector<ProgrammerWindow*> windows;
    for (Programmer p : repoP.getProgrammers())
    {
        auto window = new ProgrammerWindow(cont, p, nullptr);
        windows.push_back(window);
        window->show();
        
    }
    return a.exec();
}
