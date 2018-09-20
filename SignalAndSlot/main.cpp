#include <QApplication>
#include "myclass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyClass myclass;
    a.exec();

    return 0;
}
