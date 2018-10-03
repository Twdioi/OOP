#include <QtWidgets>

#include <cmath>

#include "button.h"
#include "calc.h"
#include "history.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    sumInMemory = 0.0;
    sumSoFar = 0.0;//сохраняет суммарное значение всех вводимых значений. Когда пользователь щелкает по =,
    //sumSoFar перерассчитывается и отображается на экране. Clear All сбрасывает значение sumSoFar в ноль.
    factorSoFar = 0.0; // сохраняет временное значение при выполнении умножений и делений
    waitingForOperand = true; // равен true когда калькулятор ожидает начала набора пользователем операнда.

    display = new QLineEdit("0"); //однострочный текст
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);//выравнивание для компановщика, по правому краю
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    for (int i = 0; i < NumDigitButtons; ++i) {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *changeSignButton = createButton(tr("\302\261"), SLOT(changeSignClicked()));

    Button *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    //Button *clearButton = createButton(tr("Clear"), SLOT(clear()));
    Button *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));

//    Button *clearMemoryButton = createButton(tr("MC"), SLOT(clearMemory()));
//    Button *readMemoryButton = createButton(tr("MR"), SLOT(readMemory()));
//    Button *setMemoryButton = createButton(tr("MS"), SLOT(setMemory()));
//    Button *addToMemoryButton = createButton(tr("M+"), SLOT(addToMemory()));

    Button *division = createButton(tr("/"), SLOT(multiplicativeOperatorClicked()));
    Button *multiplication = createButton(tr("*"), SLOT(multiplicativeOperatorClicked()));
    Button *minus = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Button *plus = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Button *square = createButton(tr("Sqrt"), SLOT(oneClickOperator()));
    Button *power = createButton(tr("x^2"), SLOT(oneClickOperator()));
    Button *equal = createButton(tr("="), SLOT(equalClicked()));

    Button *ln = createButton(tr("ln"), SLOT(oneClickOperator()));
    Button *exp = createButton(tr("exp"), SLOT(oneClickOperator()));

    Button *sin = createButton(tr("sin"), SLOT(trigonometricClicked()));
    Button *tan = createButton(tr("tan"), SLOT(trigonometricClicked()));
    Button *cos = createButton(tr("cos"), SLOT(trigonometricClicked()));

    Button *history = createButton(tr("history"), SLOT(historyClick()));

    QGridLayout *mainLayout = new QGridLayout; //выравнивание виджетов по сетке
    mainLayout->setSizeConstraint(QLayout::SetFixedSize); //режим изменения размера комп., виджет всегда выводится на экран с оптимальными размерами

    mainLayout->addWidget(display, 0, 0, 1, 6);// добавляет виджет widget в ячейку сетки,
    //растягивая его на несколько строк/столбцов.
    //Начальная ячейка (row, column) растягивается на rowSpan строк и columnSpan столбцов.
    mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);

    mainLayout->addWidget(history, 1, 2, 1, 2);

    mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

    mainLayout->addWidget(exp, 2, 0);
    mainLayout->addWidget(sin, 3, 0);
    mainLayout->addWidget(cos, 4, 0);
    mainLayout->addWidget(tan, 5, 0);

    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    mainLayout->addWidget(digitButtons[0], 5, 1);
    mainLayout->addWidget(pointButton, 5, 2);
    mainLayout->addWidget(changeSignButton, 5, 3);

    mainLayout->addWidget(division, 2, 4);
    mainLayout->addWidget(multiplication, 3, 4);
    mainLayout->addWidget(minus, 4, 4);
    mainLayout->addWidget(plus, 5, 4);

    mainLayout->addWidget(square, 2, 5);
    mainLayout->addWidget(power, 3, 5);
   // mainLayout->addWidget(reciprocalButton, 4, 5);
    mainLayout->addWidget(ln, 4, 5);
    mainLayout->addWidget(equal, 5, 5);
    setLayout(mainLayout);

    setWindowTitle(tr("Calculator"));
}

void Calculator::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender()); //узнаем какая кнопка отправила сигнал
    int digitValue = clickedButton->text().toInt();//считывает значение
    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        display->clear(); // очистка результата
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue)); // + новая цифра на экран
}

void Calculator::historyClick()
{
 h->his();
 //h->getwindow()->show();
}

void Calculator::oneClickOperator()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if (clickedOperator == tr("Sqrt")) {
        if (operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);
    } else if (clickedOperator == tr("x^2")) {
        result = std::pow(operand, 2.0);
    } else if (clickedOperator == tr("ln")) {
        if (operand == 0.0) {
            abortOperation();
            return;
        }
        result =log(operand);
    } else if (clickedOperator == tr("exp")){
        result = exp(operand);
    }
    display->setText(QString::number(result));
    waitingForOperand = true; // //цифра рассматривается как новый операнд
}



void Calculator::trigonometricClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if (clickedOperator == tr("sin")){
        double s = sin(operand * 3.14159265 / 180);
        h->getjurnal()->setText(h->getjurnal()->text() + "sin(" + QString::number(operand) + ") = " + QString::number(s) + "\n");
        result = s;

        }
    else if (clickedOperator == tr("tan")){
                result = tan(operand * 3.14159265 / 180);}

    else if (clickedOperator == tr("cos")){
       result = cos(operand * 3.14159265 / 180);}

    display->setText(QString::number(result));
    waitingForOperand = true; // //цифра рассматривается как новый операнд
}



void Calculator::additiveOperatorClicked() //плюс минус
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) { //истина если нет символов
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }

    if (!AdditiveOperator.isEmpty()) {
        if (!calculate(operand, AdditiveOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }

    AdditiveOperator = clickedOperator; //запоминает какой операнд нажат
    waitingForOperand = true;
}

void Calculator::multiplicativeOperatorClicked() // умнож и дел
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::equalClicked()
{
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!AdditiveOperator.isEmpty()) {
        if (!calculate(operand, AdditiveOperator)) {
            abortOperation();
            return;
        }
        AdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculator::pointClicked()
{
    if (waitingForOperand)
        display->setText("0");
    if (!display->text().contains('.')) // истина если выражение встречатеся в строке
        display->setText(display->text() + tr("."));
    waitingForOperand = false;
}

void Calculator::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend(tr("-")); //добавляет "-" к началу
    } else if (value < 0.0) {
        text.remove(0, 1);//удаляет первый символ в значении (сам минус)
    }
    display->setText(text);
}

void Calculator::backspaceClicked()
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

void Calculator::clear() //сбрасывает значение текущего операнда в ноль
{
    if (waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    AdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    display->setText("0");
    waitingForOperand = true;
}

//void Calculator::clearMemory()
//{
//    sumInMemory = 0.0;
//}

//void Calculator::readMemory()
//{
//    display->setText(QString::number(sumInMemory));
//    waitingForOperand = true;
//}

//void Calculator::setMemory()
//{
//    equalClicked();
//    sumInMemory = display->text().toDouble();
//}

//void Calculator::addToMemory()
//{
//    equalClicked();
//    sumInMemory += display->text().toDouble();
//}

Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculator::abortOperation()
{
    clearAll();
    display->setText(tr("####"));
}

bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("*")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("/")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}
