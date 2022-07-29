#include "ScreenWriting.h"
#include "WriterWindow.h"
#include <QtWidgets/QApplication>
#include "Repo.h"
#include "Cont.h"
#include <vector>
#include "TableModel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo;
    Controller cont(repo);
    vector<WriterWindow*> windows;
    TableModel* model = new TableModel(cont);
    for (auto& w : repo.getWriters())
    {
        auto window = new WriterWindow(model, w, nullptr);
        windows.push_back(window);
        window->show();
    }
    return a.exec();
}
