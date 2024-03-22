#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QElapsedTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void updateTimer();
    void updateTimeDisplay(qint64 elapsed);

private:
    QLabel *label;
    QTimer *timer;
    QElapsedTimer elapsedTimer;
    qint64 elapsedTime;
};

#endif // MAINWINDOW_H
