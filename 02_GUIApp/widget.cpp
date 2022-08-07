#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(300, 200);

    str = QString("Hello world!");
    button = new QPushButton(str, this);
    button->setGeometry(10, 10, 100, 30);

    connect(button, &QPushButton::clicked, this, &Widget::SlotButton);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SlotButton()
{
    static int pushCount = 0;

    qDebug("Button clicked! %d", pushCount);
    pushCount++;
}
