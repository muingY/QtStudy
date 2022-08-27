#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    date[0] = QDate(2022, 3, 9);
    date[1] = QDate::currentDate();

    dateEdit[0] = new QDateEdit(date[0], this);
    dateEdit[0]->setGeometry(10, 10, 140, 40);

    dateEdit[1] = new QDateEdit(date[1], this);
    dateEdit[1]->setGeometry(10, 50, 140, 40);

    dateLabel[0] = new QLabel(date[0].toString(Qt::ISODate), this);
    dateLabel[0]->setGeometry(10, 300, 200, 30);

    dateLabel[1] = new QLabel(date[1].toString(Qt::ISODate), this);
    dateLabel[1]->setGeometry(10, 350, 200, 30);
}

Widget::~Widget()
{
    delete dateEdit[0];
    delete dateEdit[1];
    delete dateLabel[0];
    delete dateLabel[1];
    delete ui;
}
