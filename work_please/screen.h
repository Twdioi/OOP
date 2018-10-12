#ifndef SCREEN_H
#define SCREEN_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
//#include "history.h"
#include "calculator.h"

class history;
class calculator;

class QLineEdit;

class screen : public QWidget
{
    Q_OBJECT

public:
    screen(QWidget *parent = 0);
    QPushButton* createButton (const QString& str, const char *member);

    QString Button();
    QString ClickOperator();
    QString consider();

    QString operator_text = "";
    void setOperatorText(QString s);

    QString getOperatorText();

    void output(double r);
    bool waitingForOperand;


//private slots:
   void digitClicked(/*QString str*/);
//    void oneClickOperator();
//    void additiveOperatorClicked();
//    void multiplicativeOperatorClicked();
//    void equalClicked();
//    void pointClicked();
//    void changeSignClicked();
//    void backspaceClicked();



//    void clearAll();
//    void trigonometricClicked();

//    void historyClick();
 public slots:
  void slotButtonClicked();
  void digit();
  void click_oneClickOperator();
  void click_trigonometricOperator();
  void click_additiveOperation();
  void click_multiplicativeOperation();
  void clear();
  void backspaceClicked();
  void pointClicked();
  void changeSignClicked();
  void equalClicked();

  void destv();

private:
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
   // bool waitingForOperand;// равен true когда калькулятор ожидает начала набора пользователем операнда.

    QLineEdit *display; //строка
    history *h;
    calculator *c;
    QChar NumDigitButtons[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

};

#endif
