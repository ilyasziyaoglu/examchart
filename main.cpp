#include "login.h"

#include <QApplication>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.show();
    return a.exec();
}
