#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow* NewInstance();
    bool construct();

    ~MainWindow();
protected:
    MainWindow(QWidget *parent = 0);

    bool initMenuBar();
    bool initToolBar();

    bool initFileMenu(QMenuBar*);
};

#endif // MAINWINDOW_H
