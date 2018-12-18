#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret = new MainWindow();

    if((ret == NULL)||!(ret->construct()))
    {
        delete ret;
        ret = NULL;
    }
    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;
    ret = ret && initMenuBar();
    ret = ret && initToolBar();

    return ret;
}
bool MainWindow::initMenuBar()
{
    bool ret = true;
    QMenuBar* mb = menuBar();
    ret = ret && initFileMenu(mb);

    return ret;
}
bool MainWindow::initToolBar()
{
    bool ret = true;
    QToolBar* toolbar = addToolBar("Tool Bar");

    return ret;
}
bool MainWindow::initFileMenu(QMenuBar* mb)
{
    bool ret = true;

    return ret;
}
MainWindow::~MainWindow()
{

}
