#include "myqlineseries.h"

MyQLineSeries::MyQLineSeries(QLineSeries *parent) : QLineSeries(parent)
{

}

MyQLineSeries::~MyQLineSeries()
{

}

void MyQLineSeries::set_Y_Axis_Range(double y_min, double y_max)
{
    qDebug() <<"set_Y_Axis_Range";
    yAxis->setRange(y_min, y_max);
}

void MyQLineSeries::set_X_Axis_Range(double x_min, double x_max)
{
    qDebug() <<"set_X_Axis_Range";
    xAxis->setRange(x_min, x_max);
}

QChart *MyQLineSeries::create_chart()
{  
    qDebug() <<"create_chart  ... ";
    chart->setTheme(QChart::ChartThemeQt);
//    chart->setTitle("显示坐标点");
    chart->setMargins(QMargins(10, 10, 10, 10));
    xAxis->setRange(0, 20);
    yAxis->setRange(0, 10);
    xAxis->setTitleText(QStringLiteral("X轴"));
    xAxis->setTitleFont(QFont("宋体"));
    yAxis->setTitleText(QStringLiteral("Y轴"));
    yAxis->setTitleFont(QFont("宋体"));

//    brush->setStyle(Qt::SolidPattern);
//    brush->setColor(Qt::red);
//    xAxis->setTitleBrush(brush);
// 轴标签设置
//    xAxis->setLabelFormat("%.1f");
//    xAxis->setLabelsAngle(45);
//    xAxis->setLabelsColor(Qt::blue);
//    xAxis->setLabelsEditable(true);
// 轴线和刻度线设置
//    xAxis->setTickCount(5);
//    pen->setStyle(Qt::SolidLine);
//    pen->setColor(Qt::red);
    pen->setWidth(3);
//    xAxis->setLinePen(pen);
//    xAxis->setLineVisible(true);
//    xAxis->setLinePenColor(Qt::blue);
// 主网格线设置
//    xAxis->setGridLineVisible(true);
//    xAxis->setGridLineColor(Qt::black);
// 次刻度和次网格线设置
//    xAxis->setMinorTickCount(1);
//    xAxis->setMinorGridLineColor(Qt::red);

    chart->addSeries(series);
    chart->addAxis(xAxis, Qt::AlignBottom);
    chart->addAxis(yAxis, Qt::AlignLeft);

    *series0 << QPointF(1, 5)<< QPointF(3, 7);
    *series1 << QPointF(1, 3)<< QPointF(3, 4);
    //    *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
    //             << QPointF(16, 7) << QPointF(18, 5);
    //    *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
    //             << QPointF(16, 4) << QPointF(18, 3);
    series0->setName("upper");
    series1->setName("lower");
    series->setName("Area");
    series->attachAxis(xAxis);
    series->attachAxis(yAxis);
    series->setPen(*pen);
    return chart;
}

void MyQLineSeries::add_upper_point(double x, double y)
{
    *series0 << QPointF(x, y);
}

void MyQLineSeries::add_lower_point(double x, double y)
{
    *series1 << QPointF(x, y);
}

void MyQLineSeries::MyQLineSeries_clean(void)
{
    series0->clear();
    series1->clear();
}
