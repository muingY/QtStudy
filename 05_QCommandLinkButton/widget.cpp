#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(300, 300);

    cmmBtn = new QCommandLinkButton("Vision", "Vision Project", this);
    if (cmmBtn == NULL)
    {
        throw "Error: cmmBtn allocate fail.";
    }
    cmmBtn->setFlat(true);
    cmmBtn->setGeometry(50, 50, 110, 50);
    connect(cmmBtn, SIGNAL(clicked()), this, SLOT(ClickedCmmBtn()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ClickedCmmBtn()
{
    qDebug() << "Click!";
}
