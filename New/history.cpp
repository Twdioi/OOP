#include "history.h"
#include <QtWidgets>
#include <cmath>
#include "button.h"
#include "calc.h"

//extern Calculator

//history::history (QWidget *parent)
//  : QWidget(parent)
//{

//}
history::history ()
{
//    layoyt = new QVBoxLayout();
//    jurnal = new QLabel();
//    layoyt->addWidget(jurnal);




}

void history::his()
{
    window = new QWidget;
    window->resize(230,230);
    layoyt = new QVBoxLayout();
    jurnal = new QLabel();
    layoyt->addWidget(jurnal);
    window->setLayout(layoyt);
    window->show();
}

QLabel* history::getjurnal()
{
    return jurnal;
}
QWidget* history::getwindow()
{
    return window;
}
