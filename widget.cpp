#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setChart(myqlineseres.create_chart());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVisible(true);

    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(pushButton_3(bool)));
    connect(this, SIGNAL(Y_Range(double,double)), &myqlineseres, SLOT(set_Y_Axis_Range(double,double)));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(pushButton_2(bool)));
    connect(this, SIGNAL(X_Range(double,double)), &myqlineseres, SLOT(set_X_Axis_Range(double,double)));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(pushButton_4(bool)));
    connect(this, SIGNAL(Xulie1_upper(double,double)), &myqlineseres, SLOT(add_upper_point(double,double)));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(pushButton_5(bool)));
    connect(this, SIGNAL(Xulie2_lower(double,double)), &myqlineseres, SLOT(add_lower_point(double,double)));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushButton(bool)));
    connect(this, SIGNAL(clean()), &myqlineseres, SLOT(MyQLineSeries_clean()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::pushButton_3(bool y)  //Y轴范围
{
    qDebug() <<"pushButton_3"<<"Y轴范围";
    double y_min = ui->doubleSpinBox_3->value();
    double y_max = ui->doubleSpinBox_4->value();
    emit Y_Range(y_min ,y_max);
}

void Widget::pushButton_2(bool x)  //X轴范围
{
    qDebug() <<"pushButton_2"<<"X轴范围";
    double x_min = ui->doubleSpinBox->value();
    double x_max = ui->doubleSpinBox_2->value();
    emit X_Range(x_min ,x_max);
}

void Widget::pushButton_4(bool x)  //序列1
{
    qDebug()<<"pushButton_4"<<"序列1";
    qDebug()<<"doubleSpinBox_5"<< ui->doubleSpinBox_5->value();
    qDebug()<<"doubleSpinBox_6"<< ui->doubleSpinBox_6->value();
    xulie_1.append("(");
    xulie_1.append(QString::number(ui->doubleSpinBox_5->value()));
    xulie_1.append(",");
    xulie_1.append(" ");
    xulie_1.append(QString::number(ui->doubleSpinBox_6->value()));
    xulie_1.append(")");
    xulie_1.append("\n");
    ui->label_17->setText(xulie_1);
    emit Xulie1_upper(ui->doubleSpinBox_5->value(),ui->doubleSpinBox_6->value());
}

void Widget::pushButton_5(bool x)  //序列2
{
    xulie_2.append("(");
    xulie_2.append(QString::number(ui->doubleSpinBox_7->value()));
    xulie_2.append(",");
    xulie_2.append(" ");
    xulie_2.append(QString::number(ui->doubleSpinBox_8->value()));
    xulie_2.append(")");
    xulie_2.append("\n");
    ui->label_4->setText(xulie_2);
    emit Xulie2_lower(ui->doubleSpinBox_7->value(),ui->doubleSpinBox_8->value());
}

void Widget::pushButton(bool x)  //clean
{
    qDebug()<<"pushButton"<<": clean...";
    xulie_1 = "";
    xulie_2 = "";
    ui->label_17->clear();
    ui->label_4->clear();
    emit clean();
}








