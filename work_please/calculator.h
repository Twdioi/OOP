#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "screen.h"
//#include "history.h"

#include <QWidget>

class calc;

class calculator
{
public:
    calculator();

private:
    void digitClicked();


    QString But = c->Button();
    void oneClickOperator();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void trigonometricClicked();

    void historyClick();

//private:
    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);

    //состояние калькулятора
    double sumInMemory;
    double sumSoFar; //сохраняет суммарное значение всех
    //вводимых значений. Когда пользователь щелкает по =,
    //sumSoFar перерассчитывается и отображается на экране.
    //Clear All сбрасывает значение sumSoFar в ноль.

    double factorSoFar; // сохраняет временное значение при выполнении умножений и делений
    QString AdditiveOperator;//сохраняет последний аддитивный оператор, по которому щелкнул пользователь.
    QString pendingMultiplicativeOperator;//сохраняет последний мультипликативный оператор, по которому щелкнул пользователь.
    bool waitingForOperand;// равен true когда калькулятор ожидает начала набора пользователем операнда.

    enum { NumDigitButtons = 10 };//цифры
   // Button *digitButtons[NumDigitButtons];//кнопки
public:
    screen *c;
    history *h;



 };

#endif // CALCULATOR_H
