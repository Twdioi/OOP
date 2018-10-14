#include "calculator.h"
#include "screen.h"
#include <QDebug>

//#include "history.h"

calculator::calculator()
{

}


QString calculator::oneClickOperation(double & operand, QString& clickedOperator)
{
    double result = 0.0;
    if (clickedOperator == ("sqrt")) {
        if ( operand < 0.0) {
           // abortOperation();
            return "Error" ;
        }
        result = std::sqrt(operand);
    } else if (clickedOperator == ("x^2")) {
        result = std::pow( operand, 2.0);
    } else if (clickedOperator == ("ln")) {
        if ( operand == 0.0) {
            return "Error" ;
        }
        result =log( operand);
    } else if (clickedOperator == ("exp")){
        result = exp( operand);
    }
    return QString::number(result);
}


QString calculator::trigonometricOperation(double & operand, QString& clickedOperator)
{
    double result = 0.0;

    if (clickedOperator == ("sin"))
       result = sin(operand * 3.14159265 / 180);

    else if (clickedOperator == ("tan")){
       result = tan(operand * 3.14159265 / 180);}

    else if (clickedOperator == ("cos")){
       result = cos(operand * 3.14159265 / 180);}

    return QString::number(result);
}


QString calculator::equalOpetation()
{
    double result = 0.0;
    if (clickedOperator == "+") { result = operand1+operand2; }
    else if(clickedOperator == "-") {   result = operand1-operand2;}
    else if(clickedOperator == "*"){    result = operand1*operand2;}
    else if(clickedOperator == "/"){ result = operand1/operand2;}

     return (QString::number(result));
}



