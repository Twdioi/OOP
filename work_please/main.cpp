#include "mainwindow.h"
#include "screen.h"
#include "calculator.h"
#include <QApplication>
#include <QDebug>
#include <iostream>

#include <QString>
#include <QTextStream>
QTextStream cout(stdout);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    screen s;
    s.show();
   // calculator c;
   // cout << s.operator_text;
    //cout << c.s;


    return a.exec();
}
