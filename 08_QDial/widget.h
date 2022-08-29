#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QDial>
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
    void dialValueChange(int value);

private:
    Ui::Widget *ui;

    QDial* dial;
    QLabel* dialValueLabel;
};
#endif // WIDGET_H
