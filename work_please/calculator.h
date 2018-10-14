#ifndef CALCULATOR_H
#define CALCULATOR_H
//#include "screen.h"

#include <QWidget>

class calculator
{
public:
    calculator();

public:
    void digitClicked();
    QString oneClickOperation(double& operand, QString& clickedOperator);
    QString trigonometricOperation(double& operand, QString& clickedOperator);
    QString equalOpetation();

    double operand1;
    double operand2;
    QString clickedOperator;

 };

#endif // CALCULATOR_H
