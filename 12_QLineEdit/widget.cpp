#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    for (int i = 0; i < 4; i++)
    {
        edit[i] = NULL;
        edit[i] = new QLineEdit("Sample", this);
        if (edit[i] == NULL)
            throw "Error: QLineEdit allocate fail.";
        edit[i]->setGeometry(10, i * 40 + 10, 200, 40);
    }

    edit[0]->setEchoMode(QLineEdit::Normal);
    edit[1]->setEchoMode(QLineEdit::NoEcho);
    edit[2]->setEchoMode(QLineEdit::Password);
    edit[3]->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

Widget::~Widget()
{
    for (int i = 0; i < 4; i++)
        if (edit[i] != NULL)
            delete edit[i];
    delete ui;
}

