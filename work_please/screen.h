#ifndef SCREEN_H
#define SCREEN_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "calculator.h"

class history;

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
    void setOperands();

    void output(double r);


 public slots:
  void click_digit();
  void click_oneClickOperator();
  void click_trigonometricOperator();
  void click_binaryOperation();
  void clear();
  void backspaceClicked();
  void pointClicked();
  void changeSignClicked();
  void equalClicked();


private:
    QLineEdit *display;
    calculator c;
    bool waitingForOperand;
    QChar NumDigitButtons[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

};

#endif
