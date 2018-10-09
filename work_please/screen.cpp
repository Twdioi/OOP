#include <QtWidgets>
#include <cmath>
#include "screen.h"
#include"calculator.h"
//#include "history.h"

screen::screen(QWidget *parent)
    : QWidget(parent)
{
    display = new QLineEdit("0"); //однострочный текст
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);//выравнивание для компановщика, по правому краю
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);


    QGridLayout *mainLayout = new QGridLayout; //выравнивание виджетов по сетке
    mainLayout->setSizeConstraint(QLayout::SetFixedSize); //режим изменения размера комп., виджет всегда выводится на экран с оптимальными размерами

    mainLayout->addWidget(display, 0, 0, 1, 6);// добавляет виджет widget в ячейку сетки,
    //растягивая его на несколько строк/столбцов.
    //Начальная ячейка (row, column) растягивается на rowSpan строк и columnSpan столбцов.

    mainLayout->addWidget(createButton("backspace"), 1, 0, 1, 2);
    mainLayout->addWidget(createButton("history"), 1, 2, 1, 2);
    mainLayout->addWidget(createButton("clearAll"), 1, 4, 1, 2);

    mainLayout->addWidget(createButton("exp"), 2, 0);
    mainLayout->addWidget(createButton("sin"), 3, 0);
    mainLayout->addWidget(createButton("cos"), 4, 0);
    mainLayout->addWidget(createButton("tan"), 5, 0);

    for (int i = 1; i < 10; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(createButton(NumDigitButtons[i]), row, column);
    }

    mainLayout->addWidget(createButton(NumDigitButtons[0]), 5, 1);
    mainLayout->addWidget(createButton("."), 5, 2);
    mainLayout->addWidget(createButton("\302\261"), 5, 3);

    mainLayout->addWidget(createButton("/"), 2, 4);
    mainLayout->addWidget(createButton("*"), 3, 4);
    mainLayout->addWidget(createButton("-"), 4, 4);
    mainLayout->addWidget(createButton("+"), 5, 4);

    mainLayout->addWidget(createButton("sqrt"), 2, 5);
    mainLayout->addWidget(createButton("power"), 3, 5);
    mainLayout->addWidget(createButton("ln"), 4, 5);
    mainLayout->addWidget(createButton("="), 5, 5);
    setLayout(mainLayout);

    setWindowTitle(tr("Calculator"));
}



QPushButton* screen::createButton (const QString& str) {
 QPushButton* pcmd = new QPushButton(str);
 pcmd->setMinimumSize(20, 30);
 connect(pcmd, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
 return pcmd;
}

QString screen::Button()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender()); //узнаем какая кнопка отправила сигнал
    int digitValue = clickedButton->text().toInt();//считывает значение
    return  QString::number(digitValue);
}

void screen::output(double r)
{
     display->setText(QString::number(r));
}

void screen::slotButtonClicked()
{
 QString str = ((QPushButton*)sender())->text(); //Получаем текст с нажатой кнопки
}

void screen::digitClicked(/*QString str*/) //текст передача
{
   // QPushButton *clickedButton = qobject_cast<QPushButton *>(sender()); //узнаем какая кнопка отправила сигнал
    //int digitValue = clickedButton->text().toInt();//считывает значение
   // Button();
    display->setText(display->text() + Button()); // + новая цифра на экран
}
