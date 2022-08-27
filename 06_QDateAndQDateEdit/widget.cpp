#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    dateEdit[0] = NULL;
    dateEdit[1] = NULL;
    dateLabel[0] = NULL;
    dateLabel[1] = NULL;

    date[0] = QDate(2022, 3, 9);
    date[1] = QDate::currentDate();

    dateEdit[0] = new QDateEdit(date[0], this);
    if (dateEdit[0] == NULL)
        throw "Error: QDateEdit allocation fail.";
    dateEdit[0]->setGeometry(10, 10, 140, 40);
    connect(dateEdit[0], SIGNAL(dateChanged(QDate)), SLOT(Date1Fixed(QDate)));

    dateEdit[1] = new QDateEdit(date[1], this);
    if (dateEdit[1] == NULL)
        throw "Error: QDateEdit allocation fail.";
    dateEdit[1]->setGeometry(10, 50, 140, 40);
    connect(dateEdit[1], SIGNAL(dateChanged(QDate)), SLOT(Date2Fixed(QDate)));

    dateLabel[0] = new QLabel(date[0].toString(Qt::ISODate), this);
    if (dateLabel[0] == NULL)
        throw "Error: QLabel allocation fail.";
    dateLabel[0]->setGeometry(10, 300, 200, 30);

    dateLabel[1] = new QLabel(date[1].toString(Qt::ISODate), this);
    if (dateLabel[1] == NULL)
        throw "Error: QLabel allocation fail.";
    dateLabel[1]->setGeometry(10, 350, 200, 30);
}

Widget::~Widget()
{
    if (dateEdit[0] != NULL)
        delete dateEdit[0];
    if (dateEdit[1] != NULL)
        delete dateEdit[1];
    if (dateLabel[0] != NULL)
        delete dateLabel[0];
    if (dateLabel[1] != NULL)
        delete dateLabel[1];
    delete ui;
}

void Widget::Date1Fixed(QDate date)
{
    dateLabel[0]->setText(date.toString(Qt::ISODate));
}

void Widget::Date2Fixed(QDate date)
{
    dateLabel[1]->setText(date.toString(Qt::ISODate));
}
