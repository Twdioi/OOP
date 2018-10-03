#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>

class QLineEdit;

//class Button;

class history : public QWidget
{
    Q_OBJECT

public:
    history(QWidget *parent = 0);
    void his();
private:
    QLineEdit *disp;
};

#endif // HISTORY_H
