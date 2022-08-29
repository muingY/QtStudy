#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    dial = NULL;
    dialValueLabel = NULL;

    dial = new QDial(this);
    if (dial == NULL)
        throw "error: QDial allocation fail";
    dial->setRange(0, 100);
    dial->setNotchesVisible(true);
    dial->setGeometry(30, 30, 50, 50);
    connect(dial, SIGNAL(valueChanged(int)), SLOT(dialValueChange(int)));

    dialValueLabel = new QLabel(this);
    if (dialValueLabel == NULL)
        throw "error: QLabel allocation fail";
    dialValueLabel->setText("value: " + QString::number(dial->value()));
    dialValueLabel->setGeometry(100, 40, 100, 30);
}

Widget::~Widget()
{
    if (dial != NULL)
        delete dial;
    if (dialValueLabel != NULL)
        delete dialValueLabel;
    delete ui;
}

void Widget::dialValueChange(int value)
{
    dialValueLabel->setText("value: " + QString::number(value));
}
