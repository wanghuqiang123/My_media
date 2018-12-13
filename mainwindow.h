#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow* NewInstance();
    bool construct();

    ~MainWindow();
protected:
    MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
