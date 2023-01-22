#ifndef MYQLINESERIES_H
#define MYQLINESERIES_H

#include <QObject>
#include <QWidget>
#include <QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QLocale>
#include <QValueAxis>

class MyQLineSeries : public QLineSeries
{
    Q_OBJECT

public:
    MyQLineSeries(QLineSeries *parent = nullptr);
    ~MyQLineSeries();
    QChart *create_chart();

    QChart *chart = new QChart();
    QBrush *brush = new QBrush();
    QPen *pen = new QPen(0x059605);
    QValueAxis *xAxis = new QValueAxis();
    QValueAxis *yAxis = new QValueAxis();
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    QAreaSeries *series  = new QAreaSeries(series0, series1);

signals:

public slots:
    void set_Y_Axis_Range(double y_min, double y_max);
    void set_X_Axis_Range(double x_min, double x_max);
    void add_upper_point(double x, double y);
    void add_lower_point(double x, double y);
    void MyQLineSeries_clean(void);
};

#endif // MYQLINESERIES_H
