#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(300, 300);

    comboBoxList[0] = "A";
    comboBoxList[1] = "B";
    comboBoxList[2] = "C";
    comboBoxList[3] = "D";
    comboBoxList[4] = "E";

    comboBox = new QComboBox(this);
    if(comboBox == NULL)
    {
        throw "Error: comboBox allocate fail.";
    }
    comboBox->setGeometry(50, 50, 200, 30);
    comboBox->addItem(comboBoxList[0]);
    comboBox->addItem(comboBoxList[1]);
    comboBox->addItem(comboBoxList[2]);
    comboBox->addItem(comboBoxList[3]);
    comboBox->addItem(comboBoxList[4]);
    connect(comboBox, SIGNAL(currentIndexChanged(int)), SLOT(ComboBoxChange()));
}

Widget::~Widget()
{
    if (comboBox != NULL)
    {
        delete comboBox;
    }
    delete ui;
}

void Widget::ComboBoxChange()
{
    qDebug("ComboBox change. %d", comboBox->currentIndex());
}
