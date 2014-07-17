#include "netman.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Netman w;
    w.show();

    return a.exec();
}
