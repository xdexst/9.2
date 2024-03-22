#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), seconds(0)
{
    label = new QLabel("00:00:00", this);
    setCentralWidget(label);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    timer->start(1000);//Коммит
}



void MainWindow::updateTimer()
{
    seconds++;
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    QString text = QString("%1:%2:%3")
                       .arg(hours, 2, 10, QLatin1Char('0'))
                       .arg(minutes, 2, 10, QLatin1Char('0'))
                       .arg(secs, 2, 10, QLatin1Char('0'));
    label->setText(text);
}//Rj
