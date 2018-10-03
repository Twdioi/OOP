#include "history.h"
#include <QtWidgets>
#include <cmath>
#include "button.h"
#include "calc.h"

extern Calculator

history::history (QWidget *parent)
  : QWidget(parent)
{
    //display = new QLineEdit("0"); //однострочный текст
    disp->setReadOnly(true);
   // display->setAlignment(Qt::AlignRight);//выравнивание для компановщика, по правому краю
    disp->setMaxLength(15);

    QFont font = disp->font();
    font.setPointSize(font.pointSize() + 8);
    disp->setFont(font);
}

void history::his()
{

}
