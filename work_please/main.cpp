#include "mainwindow.h"
#include "screen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    screen s;
    s.show();

    return a.exec();
}
