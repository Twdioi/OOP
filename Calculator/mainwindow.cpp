#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first; // поместит первое число введеное пользователем

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //при нажатии отслеживание сигнала, работа с данными класса(this), какой слот должен выполнится

    connect(ui->pushButton_0,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL (clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL (clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_PM,SIGNAL (clicked()), this, SLOT(operations()));
    connect(ui->pushButton_precent,SIGNAL (clicked()), this, SLOT(operations()));

    connect(ui->pushButton_slesh,SIGNAL (clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL (clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL (clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL (clicked()), this, SLOT(math_operations()));

    ui->pushButton_slesh->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digits_numbers()
{
    //получить ту кнопку которую нажали
    //в указатель будет помещаться та кнопка которая нажата
   QPushButton *button = (QPushButton*) sender();

   double all_numbers;
   QString new_lable; //переменная типа str

   if (ui->enter->text().contains(".")&&button->text() == "0")
   {
       new_lable = ui->enter->text() + button->text();
   }
   else {
   all_numbers = (ui->enter->text() + button->text()).toDouble();//соединяем числа в текстовом поле добавляем новое число, преобразовываем в дабл

   new_lable = QString::number(all_numbers, 'g', 20); // из типа дабл преобраз. обратно в строку
   }
ui->enter->setText(new_lable);
}

void MainWindow::on_pushButton_dot_clicked()
{ //текст плюс точка и числа
    if (!(ui->enter->text().contains('.'))) //если нет точки в строке тогда добавим точку иначе не будем
    ui->enter->setText(ui->enter->text() + ".");
}

void MainWindow::operations()
{
    //получить ту кнопку которую нажали
    //в указатель будет помещаться та кнопка которая нажата
   QPushButton *button = (QPushButton*) sender();

   double all_numbers;
   QString new_lable; //переменная типа str

   if(button->text() == "+/-")
   {
       all_numbers = (ui->enter->text()).toDouble();
       all_numbers = all_numbers * -1;
       new_lable = QString::number(all_numbers, 'g', 15); // из типа дабл преобраз. обратно в строку
       ui->enter->setText(new_lable);
} else if(button->text() == "%")
   {
       all_numbers = (ui->enter->text()).toDouble();
       all_numbers = all_numbers * 0.01;
       new_lable = QString::number(all_numbers, 'g', 15); // из типа дабл преобраз. обратно в строку
       ui->enter->setText(new_lable);
}

}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton*) sender();

    num_first = ui->enter->text().toDouble();

    ui->enter->setText("");
    button->setChecked(true);

}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_slesh->setChecked(false);
    ui->pushButton_pow->setChecked(false);

    ui->enter->setText("0");
}

void MainWindow::on_pushButton_equally_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->enter->text().toDouble(); // вnорое значение которое ввел пользователь

    if (ui->pushButton_plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->enter->setText(new_label);
       // ui->memory->setText(ui->memory->text() + QString::number(num_first) + " + " + QString::number(num_second) + " = " + new_label + "\n");
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->enter->setText(new_label);
       // ui->memory->setText(ui->memory->text() + QString::number(num_first) + " - " + QString::number(num_second) + " = " + new_label + "\n");
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_mult->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->enter->setText(new_label);
       // ui->memory->setText(ui->memory->text() + QString::number(num_first) + " * " + QString::number(num_second) + " = " + new_label + "\n");
        ui->pushButton_mult->setChecked(false);
    }
    else if (ui->pushButton_slesh->isChecked())
    {
        if (num_second == 0)
        {
            ui->enter->setText("0");
        }
        else
        {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);

            ui->enter->setText(new_label);
         //   ui->memory->setText(ui->memory->text() + QString::number(num_first) + " / " + QString::number(num_second) + " = " + new_label + "\n");
        }
        ui->pushButton_slesh->setChecked(false);
    }
    else if (ui->pushButton_pow->isChecked())
    {
        labelNumber = pow(num_first, num_second);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->enter->setText(new_label);
      //  ui->memory->setText(ui->memory->text() + QString::number(num_first) + "^" + QString::number(num_second) + " = " + new_label + "\n");
        ui->pushButton_pow->setChecked(false);
    }
//    else if (ui->pushButton_EXP->isChecked())
//    {
//        labelNumber = num_first * pow(10, num_second);
//        new_label = QString::number(labelNumber, 'g', 15);

//        ui->enter->setText(new_label);
//      //  ui->memory->setText(ui->memory->text() + QString::number(num_first) + " * 10^" + QString::number(num_second) + " = " + new_label + "\n");
//        ui->pushButton_exp->setChecked(false);
//    }

}
