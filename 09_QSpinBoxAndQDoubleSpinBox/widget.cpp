#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    spin = NULL;
    doubleSpin = NULL;

    spin = new QSpinBox(this);
    if (spin == NULL)
        throw "Error: QSpinBox allocate fail.";
    spin->setMinimum(10);
    spin->setMaximum(300);
    spin->setValue(50);
    spin->setPrefix("power ");
    spin->setGeometry(10, 10, 100, 30);

    doubleSpin = new QDoubleSpinBox(this);
    if (doubleSpin == NULL)
        throw "Error: QDoubleSpinBox allocate fail.";
    doubleSpin->setMinimum(10);
    doubleSpin->setMaximum(300);
    doubleSpin->setValue(50);
    doubleSpin->setGeometry(10, 40, 100, 30);
}

Widget::~Widget()
{
    if (spin != NULL)
        delete spin;
    if (doubleSpin != NULL)
        delete doubleSpin;
    delete ui;
}

