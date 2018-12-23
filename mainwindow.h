#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QIcon>
#include <QPushButton>
#include <QMenuBar>
#include <QToolBar>
#include <QSize>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QTime>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QAbstractSlider>
#include <QMediaContent>
#include <QUrl>
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
    bool initCentralwidget();
    bool initProcessSlider();
    bool initControlButton();
    bool initVolumeSlider(QHBoxLayout*&);

    bool initFileMenu(QMenuBar*);

    bool initMeidaPlayer();
protected slots:
    void StateChanged(QMediaPlayer::State state);  //当前播放器的状态
    void PositionChanged(qint64 position);
private:
    QVBoxLayout* VLayout;
    QMediaPlayer* player;
    QSlider* m_volume;
    QVector<QPushButton*>btn_cont;

    bool makeAction(QAction*& ,QWidget* , QString , int );
    bool makeControlBtn(QPushButton*&,QHBoxLayout*,QString,int);

};

#endif // MAINWINDOW_H
