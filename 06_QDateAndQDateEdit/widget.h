#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QDate>
#include <QDateEdit>
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

private:
    Ui::Widget *ui;

    QDate date[2];
    QDateEdit* dateEdit[2];
    QLabel* dateLabel[2];
};
#endif // WIDGET_H
