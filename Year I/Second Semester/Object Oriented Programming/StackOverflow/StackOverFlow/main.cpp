#include "StackOverFlow.h"
#include <QtWidgets/QApplication>
#include "UserWindow.h"
#include "SearchWindow.h"
#include "repo.h"
#include "cont.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Controller cont(repo);
    vector<UserWindow*> windows;
    for (User u : repo.getUsers())
    {
        auto window = new UserWindow(cont, u, nullptr);
        window->show();
        windows.push_back(window);
    }
    SearchWindow* searchWindow = new SearchWindow(cont, nullptr);
    searchWindow->show();
    return a.exec();
}
