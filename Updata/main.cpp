#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QComboBox>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.DetectSeriesPort();

    w.show();

    return a.exec();
}
