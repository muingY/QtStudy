#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    timeEdit1 = NULL;
    timeLabel = NULL;

    time1 = QTime(16, 42, 0, 0);

    timeEdit1 = new QTimeEdit(time1, this);
    if (timeEdit1 == NULL)
        throw "error: QTimeEdit allocation fail";
    timeEdit1->setDisplayFormat("hh:mm:ss:zzz");
    timeEdit1->setTime(time1);
    timeEdit1->setGeometry(10, 30, 150, 30);
    connect(timeEdit1, SIGNAL(timeChanged(QTime)), SLOT(TimeEdited(QTime)));

    timeLabel = new QLabel(time1.toString("hh:mm:ss:zzz"), this);
    if (timeLabel == NULL)
        throw "error: QLabel allocation fail";
    timeLabel->setGeometry(10, 100, 150, 30);
}

void Widget::TimeEdited(QTime time)
{
    time1 = time;
    timeLabel->setText(time1.toString("hh:mm:ss:zzz"));
}

Widget::~Widget()
{
    if (timeEdit1 != NULL)
        delete timeEdit1;
    if (timeLabel != NULL)
        delete timeLabel;
    delete ui;
}

