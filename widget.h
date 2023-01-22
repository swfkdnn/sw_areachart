#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <Qstring>
#include "myqlineseries.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    MyQLineSeries myqlineseres;
    QString xulie_1 = "";
    QString xulie_2 = "";

signals:
    void clean();
    void X_Range(double , double);
    void Y_Range(double , double);
    void Xulie1_upper(double , double);
    void Xulie2_lower(double , double);

public slots:
    void pushButton_3(bool x);
    void pushButton_2(bool x);
    void pushButton_4(bool x);
    void pushButton_5(bool x);
    void pushButton(bool x);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
