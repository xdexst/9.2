#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void updateTimer();

private:
    QLabel *label;
    QTimer *timer;
    int seconds;
};
#endif // MAINWINDOW_H
