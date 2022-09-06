#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QFocusFrame>

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
    void ButtonClicked();
    void ButtonPressed();
    void ButtonReleased();

private:
    Ui::Widget *ui;

    QPushButton* button[3];
    QFocusFrame* focusFrame;
};
#endif // WIDGET_H
