#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimeEdit>
#include <QLabel>

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
    void TimeEdited(QTime time);

private:
    Ui::Widget *ui;

    QTime time1;
    QTimeEdit* timeEdit1;

    QLabel* timeLabel;
};
#endif // WIDGET_H
