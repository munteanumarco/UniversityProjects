#include "TrenchCoats.h"
#include <QtWidgets/QApplication>
#include "trench_repo_files.h"
#include "trench_controller.h"
#include "trench_validator.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrenchRepoFiles repo{ "file.txt" };
    TrenchValidator val;
    TrenchController cont{ repo,val };
    TrenchCoats w{cont};
    w.show();
    return a.exec();
}
