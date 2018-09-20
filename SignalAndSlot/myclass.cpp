#include "myclass.h"

#include <QString>
#include <QApplication>

MyClass::MyClass()
{
    buttl = new QPushButton(" Передвинуть окно влево");
    buttr = new QPushButton(" Передвинуть окно вправо");
    buttu = new QPushButton(" Передвинуть окно вверх");
    buttd = new QPushButton(" Передвинуть окно вниз");

    vbox = new QVBoxLayout;
    vbox->addWidget(buttu);
    vbox->addWidget(buttl);
    vbox->addWidget(buttr);
    vbox->addWidget(buttd);

    connect(buttl, &QPushButton::clicked,this, [=](){this->newWindow(1);});
    connect(buttr, &QPushButton::clicked,this, [=](){this->newWindow(2);});
    connect(buttu, &QPushButton::clicked,this, [=](){this->newWindow(3);});
    connect(buttd, &QPushButton::clicked,this, [=](){this->newWindow(4);});

    window = new QWidget;
    window->setLayout(vbox);
    window->resize(sx,sy);
    window->move(x,y);
    window->show();
}

MyClass::MyClass(int n)
{
    buttl = new QPushButton(" Передвинуть окно влево");
    buttr = new QPushButton(" Передвинуть окно вправо");
    buttu = new QPushButton(" Передвинуть окно вверх");
    buttd = new QPushButton(" Передвинуть окно вниз");

    vbox = new QVBoxLayout;
    vbox->addWidget(buttu);
    vbox->addWidget(buttl);
    vbox->addWidget(buttr);
    vbox->addWidget(buttd);

   connect(buttl, &QPushButton::clicked,this, [=](){this->newWindow(1);});
   connect(buttr, &QPushButton::clicked,this, [=](){this->newWindow(2);});
   connect(buttu, &QPushButton::clicked,this, [=](){this->newWindow(3);});
   connect(buttd, &QPushButton::clicked,this, [=](){this->newWindow(4);});

    window = new QWidget;
    window->setLayout(vbox);
    window->resize(sx,sy);
    if (n == 1) {
        x = x - sx;
        window->move(x, y);
    }
    if (n == 2) {
        x = x + sx;
        window->move(x, y);
    }
    if (n == 3) {
        y = y - sy;
        window->move(x, y);
    }
    if (n == 4) {
        y = y + sy;
        window->move(x, y);
    }
    window->show();
}

void MyClass::newWindow(const int n)
{
    MyClass * m = new MyClass(n);
    this->~MyClass();
}

int MyClass::x = 910;
int MyClass::y = 490;
const int MyClass::sx = 100;
const int MyClass::sy = 100;
