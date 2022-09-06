#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    focusFrame = NULL;

    for (int i = 0; i < 3; i++)
    {
        button[i] = NULL;
        QString str = QString("Button %1").arg(i);
        button[i] = new QPushButton(str, this);
        if (button[i] == NULL)
            throw "Error: QPushButton allocate fail.";
        button[i]->setGeometry(10, i * 40 + 10, 300, 40);
    }

    connect(button[0], &QPushButton::clicked, this, &Widget::ButtonClicked);
    connect(button[0], &QPushButton::pressed, this, &Widget::ButtonPressed);
    connect(button[0], &QPushButton::released, this, &Widget::ButtonReleased);

    focusFrame = new QFocusFrame(this);
    if (focusFrame == NULL)
        throw "Error: QFocusFrame allocate fail.";
    focusFrame->setWidget(button[0]);
    focusFrame->setAutoFillBackground(true);
}

Widget::~Widget()
{
    for (int i = 0; i < 3; i++)
        if (button[i] != NULL)
            delete button[i];
    delete ui;
}

void Widget::ButtonClicked()
{
    qDebug("button clicked!");
}
void Widget::ButtonPressed()
{
    qDebug("button pressed!");
}
void Widget::ButtonReleased()
{
    qDebug("button released!");
}
