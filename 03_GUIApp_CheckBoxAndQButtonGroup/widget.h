#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void CheckBoxChange();

private:
    Ui::Widget* ui;

    QCheckBox* checkBox1 = NULL;
    QCheckBox* checkBox2 = NULL;

    QButtonGroup* checkBoxGroup = NULL;
};
#endif // WIDGET_H
