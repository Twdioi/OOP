#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class QLineEdit;

//class Button;

class history : public QWidget
{
    Q_OBJECT

public:
    history(QWidget *parent = 0);
    history();
    void his();
    QLabel *getjurnal();
    QWidget *getwindow();
private:
    //QLineEdit *disp;
    QWidget *window;
    QLabel *jurnal;
    QVBoxLayout *layoyt;
};

#endif // HISTORY_H
