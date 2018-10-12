#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "screen.h"
//#include "history.h"

#include <QWidget>

class calculator
{
public:
    calculator();

public:
    void digitClicked();
    QString oneClickOperation(double& operand, QString& clickedOperator);
    QString trigonometricOperation(double& operand, QString& clickedOperator);
//    QString additiveOperation(double& operand, QString& clickedOperator, QString& pendingMulOp, QString& AddOp);
//    QString multiplicativeOperation(double &operand, QString& clickedOperator, QString& pendingMulOp);
//    QString equalOpetation(double& operand, QString& pendingMulOp, QString &AddOp);

//    QString calculation(double& operand1,QString& clickedOperator,double& operand2);


    QString additiveOperation(QString& clickedOperator);
    QString multiplicativeOperation(QString& clickedOperator);
    QString equalOpetation(double& operand);

    QString calculation(double &operand1, QString &clickedOperator, double &operand2);


private:
    bool calculate(double rightOperand, const QString &pendingOperator);

    //состояние калькулятора

    double sumSoFar; //сохраняет суммарное значение всех
    //вводимых значений. Когда пользователь щелкает по =,
    //sumSoFar перерассчитывается и отображается на экране.
    //Clear All сбрасывает значение sumSoFar в ноль.

    double factorSoFar; // сохраняет временное значение при выполнении умножений и делений
 QString AdditiveOperator;//сохраняет последний аддитивный оператор, по которому щелкнул пользователь.
 QString pendingMultiplicativeOperator;//сохраняет последний мультипликативный оператор, по которому щелкнул пользователь.




 };

#endif // CALCULATOR_H
