#ifndef SCREEN_H
#define SCREEN_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
//#include "history.h"

class history;

class QLineEdit;

class screen : public QWidget
{
    Q_OBJECT

public:
    screen(QWidget *parent = 0);
    QPushButton* createButton (const QString& str);

    QString Button();

    void output(double r);


//private slots:
   void digitClicked(/*QString str*/);
//    void oneClickOperator();
//    void additiveOperatorClicked();
//    void multiplicativeOperatorClicked();
//    void equalClicked();
//    void pointClicked();
//    void changeSignClicked();
//    void backspaceClicked();
//    void clear();
//    void clearAll();
//    void trigonometricClicked();

//    void historyClick();
 public slots:
  void slotButtonClicked();


private:
   // Button *createButton(const QString &text, const char *member);
//    void abortOperation();
//    bool calculate(double rightOperand, const QString &pendingOperator);

//    //состояние калькулятора
//    double sumInMemory;
//    double sumSoFar; //сохраняет суммарное значение всех
//    //вводимых значений. Когда пользователь щелкает по =,
//    //sumSoFar перерассчитывается и отображается на экране.
//    //Clear All сбрасывает значение sumSoFar в ноль.

//    double factorSoFar; // сохраняет временное значение при выполнении умножений и делений
//    QString AdditiveOperator;//сохраняет последний аддитивный оператор, по которому щелкнул пользователь.
//    QString pendingMultiplicativeOperator;//сохраняет последний мультипликативный оператор, по которому щелкнул пользователь.
//    bool waitingForOperand;// равен true когда калькулятор ожидает начала набора пользователем операнда.

    QLineEdit *display; //строка
    history *h;
    QChar NumDigitButtons[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

};

#endif
