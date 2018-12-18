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
    QMenu* menu = new QMenu("File",mb);
    ret = (menu != NULL);
    if(ret)
    {
        QAction* action = nullptr;
        ret = ret && makeAction(action,mb,"Open(O)",Qt::CTRL+Qt::Key_O);
        if(ret)
        {
            //connect();
            menu->addAction(action);
        }
    }
    if(ret)
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}
bool MainWindow::makeAction(QAction*& action,QWidget* parent, QString text, int key)
{
    bool ret = true;

    action = new QAction(text, parent);

    if( action != NULL )
    {
        action->setShortcut(QKeySequence(key));
    }
    else
    {
        ret = false;
    }

    return ret;
}
MainWindow::~MainWindow()
{

}
