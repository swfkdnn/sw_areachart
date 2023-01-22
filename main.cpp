#include <QTranslator>
#include <QApplication>
#include <QtWidgets/QApplication>
#include <iostream>
#include "widget.h"
#include "myqlineseries.h"

using namespace std;
QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout<<"hello"<<endl;
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "sw_areachart_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Widget w;
    w.show();
    return a.exec();
}

























