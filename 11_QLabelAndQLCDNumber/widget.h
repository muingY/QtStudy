#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QLabel>
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QLabel* label[2];
    QLCDNumber* numberLCD[2];
};
#endif // WIDGET_H
