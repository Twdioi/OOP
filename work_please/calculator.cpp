#include "calculator.h"
#include "screen.h"
#include <QDebug>

//#include "history.h"

calculator::calculator()
{

}

//void calculator::() //текст передача
//{

                //void calculator::digitClicked()
                //{
                //    c->Button();
                //}



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
            //abortOperation();
            return "Error" ;
        }
        result =log( operand);
    } else if (clickedOperator == ("exp")){
        result = exp( operand);
    }
    return QString::number(result);
    //waitingForOperand = true; // //цифра рассматривается как новый операнд
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


QString calculator::additiveOperation(/*double& operand,*/ QString& clickedOperator) //плюс минус
{
   // Button *clickedButton = qobject_cast<Button *>(sender());
   // QString clickedOperator = clickedButton->text();


//    if (!pendingMultiplicativeOperator.isEmpty())
//    { //истина если нет символов
//        return (QString::number(factorSoFar));
//       // operand = factorSoFar;
//        factorSoFar = 0.0;
//        pendingMultiplicativeOperator.clear();
//    }

//    if (!AdditiveOperator.isEmpty()) {
//        return (QString::number(sumSoFar));
//    } else {
//        sumSoFar = operand;
//    }
    AdditiveOperator = clickedOperator; //запоминает какой операнд нажат
   // waitingForOperand = true;
}

QString calculator::multiplicativeOperation(/*double& operand,*/ QString& clickedOperator) // умнож и дел
{
//    Button *clickedButton = qobject_cast<Button *>(sender());
//    QString clickedOperator = clickedButton->text();
//    double operand = display->text().toDouble();
   // pendingMultiplicativeOperator = pendingMulOp;

//            if (!pendingMultiplicativeOperator.isEmpty()) {

//                return (QString::number(factorSoFar));
//            } else
//            {
//                factorSoFar = operand;
//            }

            pendingMultiplicativeOperator = clickedOperator;
    //waitingForOperand = true;
}

QString calculator::equalOpetation(double& operand)
{
    //double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {

//       // operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!AdditiveOperator.isEmpty()) {
        if (!calculate(operand, AdditiveOperator)) {
            //abortOperation();
            return"";
        }
        AdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    return (QString::number(sumSoFar));
    sumSoFar = 0.0;
    // waitingForOperand = true;
}



//QString calculator::additiveOperation(double& operand,QString& clickedOperator, QString& pendingMulOp,QString& AddOp) //плюс минус
//{
//   // Button *clickedButton = qobject_cast<Button *>(sender());
//   // QString clickedOperator = clickedButton->text();
//  //  double operand = display->text().toDouble();

//    pendingMultiplicativeOperator = pendingMulOp;
//    AdditiveOperator = AddOp;


//    if (!pendingMultiplicativeOperator.isEmpty()) { //истина если нет символов
//        if (!calculate(operand, pendingMultiplicativeOperator)) {
//           // abortOperation();
//            return "";
//        }
//        //display->setText(QString::number(factorSoFar));
//        return (QString::number(factorSoFar));
//        operand = factorSoFar;
//        factorSoFar = 0.0;
//        pendingMultiplicativeOperator.clear();
//    }

//    if (!AdditiveOperator.isEmpty()) {
//        if (!calculate(operand, AdditiveOperator)) {
//            //abortOperation();
//            return " ";
//        }
//        return (QString::number(sumSoFar));
//    } else {
//        sumSoFar = operand;
//    }
//    AdditiveOperator = "";
//    AdditiveOperator = clickedOperator; //запоминает какой операнд нажат
//   // waitingForOperand = true;
//}

//QString calculator::multiplicativeOperation(double& operand, QString& clickedOperator, QString& pendingMulOp) // умнож и дел
//{
////    Button *clickedButton = qobject_cast<Button *>(sender());
////    QString clickedOperator = clickedButton->text();
////    double operand = display->text().toDouble();
//   // pendingMultiplicativeOperator = pendingMulOp;

//            if (!pendingMultiplicativeOperator.isEmpty()) {
//                if (!calculate(operand, pendingMultiplicativeOperator)) {
//                   // abortOperation();
//                    return" Error";
//                }
//                return (QString::number(factorSoFar));
//            } else {
//                factorSoFar = operand;
//            }

//            pendingMultiplicativeOperator = clickedOperator;
//    //waitingForOperand = true;
//}

//QString calculator::equalOpetation(double& operand, QString& pendingMulOp, QString& AddOp)
//{
//    //double operand = display->text().toDouble();

//    pendingMultiplicativeOperator = pendingMulOp;
//    AdditiveOperator = AddOp;

//    if (!pendingMultiplicativeOperator.isEmpty()) {
//        if (!calculate(operand, pendingMultiplicativeOperator)) {
//            //abortOperation();
//            return"Error";
//        }
//        operand = factorSoFar;
//        factorSoFar = 0.0;
//        pendingMultiplicativeOperator.clear();
//    }
//    if (!AdditiveOperator.isEmpty()) {
//        if (!calculate(operand, AdditiveOperator)) {
//            //abortOperation();
//            return "Error";
//        }
//        AdditiveOperator.clear();
//    } else {
//        sumSoFar = operand;
//    }

//    return (QString::number(sumSoFar));
//    sumSoFar = 0.0;
//    // waitingForOperand = true;
//}

QString calculator::calculation(double &operand1, QString &clickedOperator, double &operand2 )
{
    double result = 0.0;
    if (clickedOperator == "+") { result = operand1 + operand2; }
    else if (clickedOperator == "-") { result = operand1 - operand2; }
    else if (clickedOperator == "/") { result = operand1 / operand2; }
    else if (clickedOperator == "*") { result = operand1 * operand2; }
    return (QString::number(result));
}

//void Calculator::abortOperation()
//{
//    clearAll();
//    display->setText(tr("####"));
//}

bool calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == "+") {
        sumSoFar += rightOperand;
    } else if (pendingOperator == "-") {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == "*") {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == "/") {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}

