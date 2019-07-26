#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setButton();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n) {
    money += n;
    ui->lcdNumber->display(money);
    setButton();
}

void Widget::setButton() {
    if (money >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
    if (money >= 150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
    if (money >= 200) ui->pbCoke->setEnabled(true);
    else ui->pbCoke->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int n10=0, n50=0, n100=0, n500=0;
    while (money > 0) {
        if (money >= 500) {
            n500++;
            money -= 500;
        }
        else if (money >= 100) {
            n100++;
            money -= 100;
        }
        else if (money >= 50) {
            n50++;
            money -= 50;
        }
        else {
            n10++;
            money -= 10;
        }
    }
    QString str = "";
    str.append(QStringLiteral("500 : %1\n").arg(n500));
    str.append(QStringLiteral("100 : %1\n").arg(n100));
    str.append(QStringLiteral("50  : %1\n").arg(n50));
    str.append(QStringLiteral("10  : %1\n").arg(n10));

    QMessageBox msg;
    msg.information(nullptr, "Reset", str);

    changeMoney(0);
}
