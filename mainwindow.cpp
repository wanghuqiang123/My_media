#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(400,400);
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
    ret = ret && initCentralwidget();
    ret = ret && initMeidaPlayer();

    return ret;
}
bool MainWindow::initMenuBar()
{
    bool ret = true;
    QMenuBar* mb = menuBar();
    ret = ret && initFileMenu(mb);

    return ret;
}
bool MainWindow::initMeidaPlayer()
{
    bool ret = true;
    player = new QMediaPlayer();

    player->setVolume(m_volume->value());
    connect(player,SIGNAL(stateChanged(QMediaPlayer::State state)),this,SLOT(StateChanged(QMediaPlayer::State)));
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(PositionChanged(qint64)));
    player->setMedia(QUrl::fromLocalFile("C:\\Qt\\QT_file\\Music_Player\\Qt_template\\test_misic\\1.mp3"));
    player->play();
    return ret;
}
bool MainWindow::initCentralwidget()
{
    bool ret =true;
    setCentralWidget(new QWidget());
    VLayout = new QVBoxLayout(centralWidget());

    ret = ret && initProcessSlider();
    ret = ret && initControlButton();

    return ret;
}
bool MainWindow::initProcessSlider()
{
    bool ret = true;
    QHBoxLayout* HLyout = new QHBoxLayout();
    QSlider* process_slider = new QSlider(Qt::Horizontal);
    HLyout->addWidget(process_slider);
    QLabel* label = new QLabel("00:00:00");
    HLyout->addWidget(label);
    if(label == NULL || HLyout == NULL || process_slider == NULL)
    {
        ret = false;
    }
    else
    {
        VLayout->addStretch(4);
        VLayout->addLayout(HLyout);
    }
    return ret;
}
bool MainWindow::initControlButton()
{
    bool ret = true;
    QHBoxLayout* layout = new QHBoxLayout();
    ret = (layout != NULL);
    if(ret)
    {
        QPushButton* btn = NULL;
        ret = ret && makeControlBtn(btn,layout,":/btnIcon/Icon/stop.png",Qt::Key_Stop);
        if(ret)
        {
        }
        ret = ret && makeControlBtn(btn,layout,":/btnIcon/Icon/play.png",Qt::Key_Play);
        if(ret)
        {}
        ret = ret && makeControlBtn(btn,layout,":/btnIcon/Icon/pause.png",Qt::Key_Pause);
        if(ret)
        {
        }
        layout->addSpacing(30);
        QLabel* label = new QLabel("音量：");
        layout->addWidget(label);
        ret = ret && makeControlBtn(btn,layout,":/btnIcon/Icon/volume.png",0);
        if(ret)
        {
        }
        ret = ret && initVolumeSlider(layout);
        layout->addStretch(1);
    }
    if(ret)
    {
        VLayout->addLayout(layout);
    }
    else
    {
        delete layout;
        ret = false;
    }
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
bool MainWindow::makeControlBtn(QPushButton*& btn,QHBoxLayout* layout,QString icon,int key)
{
    bool ret = true;
    btn = new QPushButton();
    if(btn != NULL)
    {
        btn->setIcon(QIcon(icon));
        btn->setShortcut(QKeySequence(key));
        layout->addWidget(btn);
        btn_cont.push_back(btn);
    }
    else
    {
        delete btn;
        ret = false;
    }
    return ret;
}
bool MainWindow::initVolumeSlider(QHBoxLayout*& layout)
{
    bool ret = true;
    QSlider* m_volume = new QSlider(Qt::Horizontal);
    if(m_volume != NULL)
    {
        m_volume->setMinimum(0);
        m_volume->setMaximum(100);
        m_volume->setSliderPosition(15);
        layout->addWidget(m_volume);
    }
    else
    {
        delete m_volume;
        ret = false;
    }
    return ret;
}
void MainWindow::StateChanged(QMediaPlayer::State state)  //当前播放器的状态
{
    if(state == QMediaPlayer::PlayingState)
    {
        btn_cont[QMediaPlayer::PlayingState]->setEnabled(false);   //当在播放的时候 播放按钮不能使能。
        btn_cont[QMediaPlayer::PausedState]->setEnabled(true);
        btn_cont[QMediaPlayer::StoppedState]->setEnabled(true);
    }
    else if(state == QMediaPlayer::PausedState)
    {
        btn_cont[QMediaPlayer::PausedState]->setEnabled(false);
        btn_cont[QMediaPlayer::StoppedState]->setEnabled(true);
        btn_cont[QMediaPlayer::PlayingState]->setEnabled(true);
    }
    else
    {
        btn_cont[QMediaPlayer::StoppedState]->setEnabled(false);
        btn_cont[QMediaPlayer::PlayingState]->setEnabled(true);
        btn_cont[QMediaPlayer::PausedState]->setEnabled(false);
    }
}
void MainWindow::PositionChanged(qint64 position)
{

}
MainWindow::~MainWindow()
{

}

