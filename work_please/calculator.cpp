#include "calculator.h"
#include "screen.h"
//#include "history.h"

calculator::calculator()
{

}

//void calculator::() //текст передача
//{

void calculator::digitClicked()
{
    c->Button();
}



void calculator::oneClickOperator()
{
//    Button *clickedButton = qobject_cast<Button *>(sender());
//    QString clickedOperator = clickedButton->text();
   double operand =c->Button().toDouble();

    double result = 0.0;

    if (But == ("Sqrt")) {
        if (operand < 0.0) {
           // abortOperation();
            return ;
        }
        result = std::sqrt(operand);
    } else if (But == ("x^2")) {
        result = std::pow(operand, 2.0);
    } else if (But == ("ln")) {
        if (operand == 0.0) {
            //abortOperation();
            return ;
        }
        result =log(operand);
    } else if (But == ("exp")){
        result = exp(operand);
    }
    c->output(result);
    waitingForOperand = true; // //цифра рассматривается как новый операнд
}

