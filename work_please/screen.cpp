#include <QtWidgets>
#include <cmath>
#include "screen.h"
#include"calculator.h"
#include <QDebug>

screen::screen(QWidget *parent)
    : QWidget(parent)
{
    waitingForOperand = true;

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

    mainLayout->addWidget(createButton("backspace",SLOT(backspaceClicked())), 1, 0, 1, 2);

    mainLayout->addWidget(createButton("clear",SLOT(clear())), 1, 4, 1, 2);

    mainLayout->addWidget(createButton("exp",SLOT(click_oneClickOperator())), 2, 0);
    mainLayout->addWidget(createButton("sin",SLOT(click_trigonometricOperator())), 3, 0);
    mainLayout->addWidget(createButton("cos",SLOT(click_trigonometricOperator())), 4, 0);
    mainLayout->addWidget(createButton("tan",SLOT(click_trigonometricOperator())), 5, 0);

    for (int i = 1; i < 10; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(createButton(NumDigitButtons[i] ,SLOT(click_digit())), row, column);
    }

    mainLayout->addWidget(createButton(NumDigitButtons[0],SLOT(click_digit())), 5, 1);
    mainLayout->addWidget(createButton(".",SLOT(pointClicked())), 5, 2);
    mainLayout->addWidget(createButton("\302\261",SLOT(changeSignClicked())), 5, 3);

    mainLayout->addWidget(createButton("/",SLOT(click_binaryOperation())), 2, 4);
    mainLayout->addWidget(createButton("*",SLOT(click_binaryOperation())), 3, 4);
    mainLayout->addWidget(createButton("-",SLOT(click_binaryOperation())), 4, 4);
    mainLayout->addWidget(createButton("+",SLOT(click_binaryOperation())), 5, 4);

    mainLayout->addWidget(createButton("sqrt",SLOT(click_oneClickOperator())), 2, 5);
    mainLayout->addWidget(createButton("x^2",SLOT(click_oneClickOperator())), 3, 5);
    mainLayout->addWidget(createButton("ln",SLOT(click_oneClickOperator())), 4, 5);
    mainLayout->addWidget(createButton("=",SLOT(equalClicked())), 5, 5);
    setLayout(mainLayout);

    setWindowTitle(tr("Calculator"));
}



QPushButton* screen::createButton (const QString& str,const char *member) {
 QPushButton* pcmd = new QPushButton(str);
 pcmd->setMinimumSize(20, 30);
 connect(pcmd, SIGNAL(clicked()), this, member);
 return pcmd;
}


QString screen::ClickOperator() // считывает какая кнопка подала сигнал
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    return (clickedButton->text());
}


void screen::click_oneClickOperator()
{
   double operand = display->text().toDouble();
   QString text = ClickOperator();
   display->setText(c.oneClickOperation(operand,text));
   waitingForOperand = true;

}

void screen::click_trigonometricOperator()
{
    double operand = display->text().toDouble();
    QString text = ClickOperator();
    display->setText(c.trigonometricOperation(operand,text));
    waitingForOperand = true;
}


void screen::click_binaryOperation()
{
    double operand = display->text().toDouble();
    c.operand1 = operand;
    QString text = ClickOperator();
    c.clickedOperator = text;
    display->clear();
}

void screen::equalClicked()
{
   double operand = display->text().toDouble();
   c.operand2 = operand;
   display->setText(c.equalOpetation());
   waitingForOperand = true;
}



void screen::click_digit()
{
    int digitValue = ClickOperator().toInt();//считывает значение

    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        display->clear(); // очистка результата
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue)); // + новая цифра на экран
}

void screen::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend("-"); //добавляет "-" к началу
    } else if (value < 0.0) {
        text.remove(0, 1);//удаляет первый символ в значении (сам минус)
    }
    display->setText(text);
}


void screen::pointClicked()
{
    if (waitingForOperand)
        display->setText("0");
    if (!display->text().contains('.')) // истина если выражение встречатеся в строке
        display->setText(display->text() + ".");
    waitingForOperand = false;
}

void screen::clear() //сбрасывает значение текущего операнда в ноль
{
    display->setText("0");
    waitingForOperand = true;
}

void screen::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1); //удалить символ справа
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}
