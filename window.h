#ifndef _WINDOW_
#define _WINDOW_

// Qt
#include <QWidget>
#include <QString>
#include <QAction>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QStatusBar>
#include <QTimeEdit>
#include <QMessageBox>
#include <QStringList>

// local
#include "ui_window.h"

class MainWindow : public QMainWindow, public Ui_MainWindow
{
	Q_OBJECT
    
public:

    MainWindow();
    ~MainWindow();
    QToolBar *currentTool;
    double max_runtime;
    long time_counter;
    int BIN_COUNT;
    double WIND_DIST_X;
    double WIND_DIST_Y;
    double OBSTACLE_RADIUS;
    double amplitude;
    std::string stringHistogram;
    std::string stringRadius;
    std::string stringHeatMap;


	QString mode;
    QString string_time;
    QString interaction;
    QString obstacle_mode;
    QString oscillation_mode;
    QString string_wind_x;
    QString string_wind_y;
    QString string_wind_xy;
    QStringList list_wind_xy;
    QMessageBox information;
    QWidget widget;
    QPlainTextEdit *timetime;
    QPlainTextEdit *testing;
    QPlainTextEdit *windwind;
    void createStatusBar();

    
public slots:

    void on_actionRandom_Circles_triggered();
    void on_actionCircles_toggled();
    void activate_obstacles();
    void timer_update();
    void setObstacleRadius_window();
    void play();
    void pause();
    void quit();
    void coordinates();
    void radius();
    void restart();
    void default_values();
    void bin_count_window();
    void upWind();
    void downWind();
    void rightWind();
    void leftWind();

private:

    int per_row;
    bool isMovingParticles;
    bool isMovingObstacles;
    QToolBar *belowTool;
    QToolBar *fileToolBar;

    QAction *restartAct;
    QAction *exitAct;
    QAction *pauseAct;
    QAction *playAct;
    QAction *obstacleAct;
    QAction *coordAct;
    QAction *radAct;
    QAction *binAct;
    QAction *timeAct;
    QAction *defaultAct;
    QAction *upWindAct;
    QAction *downWindAct;
    QAction *leftWindAct;
    QAction *rightWindAct;
    QAction *WindAct;
    QAction *OrAct;
};


#endif
