#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(300, 300);

    checkBox1 = new QCheckBox("check box 1", this);
    if (checkBox1 == NULL)
    {
        throw "ERROR: checkBox1 allocation fail";
    }
    checkBox2 = new QCheckBox("check box 2", this);
    if (checkBox2 == NULL)
    {
        throw "ERROR: checkBox2 allocation fail";
    }
    checkBoxGroup = new QButtonGroup(this);
    if (checkBoxGroup == NULL)
    {
        throw "Error: checkBoxGroup allocation fail";
    }

    checkBox1->setGeometry(50, 50, 100, 30);
    checkBoxGroup->addButton(checkBox1);
    connect(checkBox1, SIGNAL(clicked()), this, SLOT(CheckBoxChange()));

    checkBox2->setGeometry(50, 100, 100, 30);
    checkBoxGroup->addButton(checkBox2);
    connect(checkBox2, SIGNAL(clicked()), this, SLOT(CheckBoxChange()));
}

Widget::~Widget()
{
    if (checkBox1 != NULL)
    {
        delete checkBox1;
    }
    if (checkBox2 != NULL)
    {
        delete checkBox2;
    }
    if (checkBoxGroup != NULL)
    {
        delete checkBoxGroup;
    }
    delete ui;
}

void Widget::CheckBoxChange()
{
    if (checkBox1->checkState())
    {
        qDebug() << "checkBox1 checked!";
    }
    if (checkBox2->checkState())
    {
        qDebug() << "checkBox2 checked!";
    }
}
