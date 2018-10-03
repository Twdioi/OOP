#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

class QLineEdit;

class Button;

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);

private slots:
    void digitClicked();
    void unaryOperatorClicked();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
   // void clearMemory();
//    void readMemory();
//    void setMemory();
   // void addToMemory();

private:
    Button *createButton(const QString &text, const char *member);
    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);

    //состояние калькулятора
    double sumInMemory;
    double sumSoFar; //сохраняет суммарное значение всех
    //вводимых значений. Когда пользователь щелкает по =,
    //sumSoFar перерассчитывается и отображается на экране.
    //Clear All сбрасывает значение sumSoFar в ноль.

    double factorSoFar; // сохраняет временное значение при выполнении умножений и делений
    QString pendingAdditiveOperator;//сохраняет последний аддитивный оператор, по которому щелкнул пользователь.
    QString pendingMultiplicativeOperator;//сохраняет последний мультипликативный оператор, по которому щелкнул пользователь.
    bool waitingForOperand;// равен true когда калькулятор ожидает начала набора пользователем операнда.

    QLineEdit *display;

    enum { NumDigitButtons = 10 };//цифры
    Button *digitButtons[NumDigitButtons];//кнопки
};

#endif
