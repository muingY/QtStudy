#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(500, 500);

    label[0] = NULL;
    label[1] = NULL;
    numberLCD[0] = NULL;
    numberLCD[1] = NULL;

    label[0] = new QLabel("Qt programming", this);
    if (label[0] == NULL)
        throw "Error: QLabel allocate fail.";
    label[0]->setGeometry(10, 30, 130, 40);

    label[1] = new QLabel(this);
    if (label[1] == NULL)
        throw "Error: QLabel allocate fail.";
    QPixmap pix = QPixmap(":resources/browser.png");
    label[1]->setPixmap(pix);
    label[1]->setGeometry(10, 70, 100, 100);

    numberLCD[0] = new QLCDNumber(2, this);
    if (numberLCD[0] == NULL)
        throw "Error: QLCDNumber allocate fail.";
    numberLCD[0]->display(24);
    numberLCD[0]->setGeometry(150, 30, 200, 100);
    numberLCD[0]->setSegmentStyle(QLCDNumber::Outline);

    numberLCD[1] = new QLCDNumber(5, this);
    if (numberLCD[1] == NULL)
        throw "Error: QLCDNumber allocate fail.";
    numberLCD[1]->display("18:14");
    numberLCD[1]->setGeometry(150, 140, 200, 100);
    numberLCD[1]->setSegmentStyle(QLCDNumber::Filled);
    //numberLCD[1]->setSegmentStyle(QLCDNumber::Flat);
}

Widget::~Widget()
{
    for (int i = 0; i < 2; i++)
    {
        if (label[i] != NULL)
            delete label[i];
        if (numberLCD[i] != NULL)
            delete numberLCD[i];
    }
    delete ui;
}

