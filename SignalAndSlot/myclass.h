#ifndef MYCLASS_H
#define MYCLASS_H

#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <QHBoxLayout>
#include <QDebug>

//отображение числа нажатий
class MyClass:public QObject
{
Q_OBJECT
private:
    QPushButton * buttl;
    QPushButton * buttr;
    QPushButton * buttu;
    QPushButton * buttd;
    QVBoxLayout * vbox;
    QWidget * window;
    static int x, y;
    static const int sx, sy;
public:
    MyClass();
    MyClass(int n);
    ~MyClass()
    {
        qDebug()<<"delete object MyClass";
        delete buttl;
        delete buttr;
        delete buttu;
        delete buttd;
        delete vbox;
        delete window;
    }

private slots:
    void newWindow(const int n);
signals:
    s_transmitter();
};

#endif // MYCLASS_H
