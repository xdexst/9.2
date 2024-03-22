#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), elapsedTime(0)
{
    label = new QLabel("00:00:00", this);
    setCentralWidget(label);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    timer->start(1000);
    elapsedTimer.start();
}

void MainWindow::updateTimer()
{
    qint64 elapsed = elapsedTimer.elapsed() + elapsedTime;
    updateTimeDisplay(elapsed);
}

void MainWindow::updateTimeDisplay(qint64 elapsed)
{
    int hours = elapsed / 3600000;
    int minutes = (elapsed % 3600000) / 60000;
    int seconds = (elapsed % 60000) / 1000;
    QString timeStr = QString("%1:%2:%3")
                          .arg(hours, 2, 10, QLatin1Char('0'))
                          .arg(minutes, 2, 10, QLatin1Char('0'))
                          .arg(seconds, 2, 10, QLatin1Char('0'));
    label->setText(timeStr);
}
