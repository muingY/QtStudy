#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCommandLinkButton>

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
    void ClickedCmmBtn();

private:
    Ui::Widget* ui;

    QCommandLinkButton* cmmBtn = NULL;
};
#endif // WIDGET_H
