//========== HEADER FILES ========== //

// Qt
#include <QtGui>
#include <QTimer>
#include <QInputDialog>
#include <QFrame>
// local
#include "window.h"

// Random Walk Parameters
#include "randomWalk.h"

//========== FUNCTIONS ========== //


MainWindow::MainWindow() : QMainWindow(), Ui_MainWindow()
{
    // Initialize isMovingCircles, if we want to add a keyevent to
    // pause the moving circles we can call this, right now we make
    // sure that we only call it when we have circles inflated, but
    // it shouldn't matter, since the function only changes defined
    // points, so it should cause an issue if it's called even without
    // circles instantiated
    isMovingParticles = false;
    isMovingObstacles = false;
    time_counter = 0.00;
    WIND_DIST_Y = 0.00;
    WIND_DIST_X = 0.00;
    OBSTACLE_RADIUS = .06;
    QString string_time = QString::number(time_counter,16);
    QString string_wind_x = QString::number(WIND_DIST_X);
    QString string_wind_y = QString::number(WIND_DIST_Y);
    QStringList list_wind_xy;
    list_wind_xy << string_wind_x << string_wind_y;
    QString string_wind_xy = list_wind_xy.join(",");

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setStatusTip(tr("exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(quit()));

    pauseAct = new QAction(tr("&Pause"), this);
    pauseAct->setStatusTip(tr("pause the simulation"));
    connect(pauseAct, SIGNAL(triggered()), this, SLOT(pause()));

    playAct = new QAction(tr("&Play"), this);
    playAct->setStatusTip(tr("continue the simulation"));
    connect(playAct, SIGNAL(triggered()), this, SLOT(play()));
     
    obstacleAct = new QAction(tr("&Oscillation"), this);
    obstacleAct->setStatusTip(tr("make the cilia oscillate"));
    connect(obstacleAct, SIGNAL(triggered()), this, SLOT(activate_obstacles()));

    coordAct = new QAction(tr("&Coordinates"), this);
    coordAct->setStatusTip(tr("print the coordinates data"));
    connect(coordAct, SIGNAL(triggered()), this, SLOT(coordinates()));
     
    radAct = new QAction(tr("&Radius"), this);
    radAct->setStatusTip(tr("print the radius data"));
    connect(radAct, SIGNAL(triggered()), this, SLOT(radius()));

    restartAct = new QAction(tr("&Restart"), this);
    restartAct->setStatusTip(tr("restart"));
    connect(restartAct, SIGNAL(triggered()), this, SLOT(restart()));

    defaultAct = new QAction(tr("&Default"), this);
    defaultAct->setStatusTip(tr("restart the simulation with default values"));
    connect(defaultAct, SIGNAL(triggered()), this, SLOT(default_values()));

    binAct = new QAction(tr("&Bins"), this);
    binAct->setStatusTip(tr("set the number of bins for histogram"));
    connect(binAct, SIGNAL(triggered()), this, SLOT(bin_count_window()));

    timeAct = new QAction(tr("&Time Elapsed:"), this);
    binAct->setStatusTip(tr("displaying the total time elapsed in milliseconds"));

    WindAct = new QAction(tr("&Wind:"), this);
    WindAct->setStatusTip(tr("Use the controls to increase or decrease wind"));

    upWindAct = new QAction(tr("&Up"), this);
    upWindAct->setStatusTip(tr("increase wind upwards"));
    connect(upWindAct, SIGNAL(triggered()), this, SLOT(upWind()));
    downWindAct = new QAction(tr("&Down"), this);
    downWindAct->setStatusTip(tr("increase wind downwards"));
    connect(downWindAct, SIGNAL(triggered()), this, SLOT(downWind()));
    leftWindAct = new QAction(tr("&Left"), this);
    leftWindAct->setStatusTip(tr("increase wind towards the left"));
    connect(leftWindAct, SIGNAL(triggered()), this, SLOT(leftWind()));
    rightWindAct = new QAction(tr("&Right"), this);
    rightWindAct->setStatusTip(tr("increase wind towards the right"));
    connect(rightWindAct, SIGNAL(triggered()), this, SLOT(rightWind()));
     
    OrAct = new QAction(tr("&Obstacle Size"), this);
    OrAct->setStatusTip(tr("set the Obstacle Size (radius)"));
    connect(OrAct, SIGNAL(triggered()), this, SLOT(setObstacleRadius_window()));

    //endtime = new QTimeEdit();
    timetime = new QPlainTextEdit(string_time);
    timetime->setReadOnly(true);
    timetime->setMaximumHeight(25);
    timetime->setMaximumWidth(80);
    
    windwind = new QPlainTextEdit(string_wind_xy);
    windwind->setReadOnly(true);
    windwind->setMaximumHeight(25);
    windwind->setMaximumWidth(100);


    fileToolBar = addToolBar(tr("Tools"));
    fileToolBar->addAction(exitAct);
    fileToolBar->addAction(pauseAct);
    fileToolBar->addAction(playAct);
    fileToolBar->addAction(timeAct);
    fileToolBar->addWidget(timetime);
    fileToolBar->addAction(restartAct);
    fileToolBar->addAction(defaultAct);
    fileToolBar->addAction(binAct);
    fileToolBar->addAction(coordAct);
    fileToolBar->addAction(radAct);


    currentTool = addToolBar(tr("controls"));
    currentTool->addAction(obstacleAct);
    currentTool->addAction(WindAct);
    currentTool->addWidget(windwind);
    currentTool->addAction(upWindAct);
    currentTool->addAction(downWindAct);
    currentTool->addAction(leftWindAct);
    currentTool->addAction(rightWindAct);
    currentTool->addAction(OrAct);
    

    fileToolBar->setAllowedAreas(Qt::BottomToolBarArea);
    addToolBar(Qt::BottomToolBarArea, fileToolBar);

    // Start the timer with interval TIMER_INTERVAL, which is defined in
    // randomWalk.h. This calls timer_update() ever TIMER_INTERVAL ms
    QTimer *timer = new QTimer(this);
    QString it;

    //establish connections
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_update()));

    timer->start(TIMER_INTERVAL);

    setupUi(this);

}

MainWindow::~MainWindow()
{
}

void MainWindow::createStatusBar()
 {

    statusBar()->showMessage(tr("ready"));

 }

void MainWindow::play()
{
    if (isMovingParticles == false)
    {
        isMovingParticles = true;
    }
}

void MainWindow::pause()
{
    if (isMovingParticles == true)
    {
        isMovingParticles = false;
    }
}

void MainWindow::activate_obstacles()
{
    isMovingParticles = false;
    bool ok;
    QStringList oscillation_modes;
    oscillation_modes << tr("Off") <<tr("Random") <<tr("Together") <<tr("Alternating") <<tr("Tiered");
    this->oscillation_mode = QInputDialog::getItem(this, tr("Mode"), tr("mode:"), oscillation_modes, 0, false, &ok);
    amplitude = QInputDialog::getDouble(this, "Oscillation Amplitude", "amplitude:", .01, .001, 1, 3, &ok);
    if (!ok) return;
    if (oscillation_mode.contains("Off"))
    {
        isMovingObstacles = false;
    }
    else
    {
    isMovingObstacles = !isMovingObstacles;
    }
    isMovingParticles = true;
}

void MainWindow::quit()
{
    qApp->exit();
}

void MainWindow::coordinates()
{
    stringHistogram = (viewer->output_position(BIN_COUNT)).toUtf8().constData();;
    stringHeatMap = (viewer->output_position_heat(BIN_COUNT)).toUtf8().constData();;
}

void MainWindow::radius()
{   
    stringRadius = (viewer->radius_data(BIN_COUNT)).toUtf8().constData();
}

void MainWindow::setObstacleRadius_window()
{
    pause();
    bool ok;
    OBSTACLE_RADIUS = QInputDialog::getDouble(this, "Obstacle Radius", "#:", .06, .001, 1000, 3, &ok);
    if (!ok) return;
    viewer->setObstacleRadius(OBSTACLE_RADIUS);
    play();
}

void MainWindow::upWind()
{
    WIND_DIST_Y += .001;
    string_wind_y = QString::number(WIND_DIST_Y);
    list_wind_xy = QStringList();
    list_wind_xy << string_wind_x << string_wind_y;
    QString string_wind_xy = list_wind_xy.join(",");
    windwind->setPlainText(string_wind_xy);
}

void MainWindow::downWind()
{
    WIND_DIST_Y -= .001;
    string_wind_y = QString::number(WIND_DIST_Y);
    list_wind_xy = QStringList();
    list_wind_xy << string_wind_x << string_wind_y;
    QString string_wind_xy = list_wind_xy.join(",");
    windwind->setPlainText(string_wind_xy);
}

void MainWindow::leftWind()
{
    WIND_DIST_X -= .001;
    string_wind_x = QString::number(WIND_DIST_X);
    list_wind_xy = QStringList();
    list_wind_xy << string_wind_x << string_wind_y;
    QString string_wind_xy = list_wind_xy.join(",");
    windwind->setPlainText(string_wind_xy);
}

void MainWindow::rightWind()
{
    WIND_DIST_X += .001;
    string_wind_x = QString::number(WIND_DIST_X);
    list_wind_xy = QStringList();
    list_wind_xy << string_wind_x << string_wind_y;
    QString string_wind_xy = list_wind_xy.join(",");
    windwind->setPlainText(string_wind_xy);
}


void MainWindow::on_actionRandom_Circles_triggered()
{
    bool ok;
    max_runtime = QInputDialog::getDouble(this, "Numbers", "Max Runtime:", 100, 1, 100000, 1, &ok);
    
    int np = QInputDialog::getInt(this, "Numbers", "particles:", 10, 1, 100000, 1, &ok);
    int nob = QInputDialog::getInt(this, "Numbers", "obstacles:", 10, 0, 1000, 1, &ok);
   
    QStringList modes;
    modes <<tr("Discrete") <<tr("Continuous");
    this->mode = QInputDialog::getItem(this, tr("Particle Movement"), tr("mode:"), modes, 0, false, &ok);

    QStringList interactions;
    interactions <<tr("Disappear") <<tr("Stick") <<tr("Reflect") <<tr("Ignore");
    this->interaction = QInputDialog::getItem(this, tr("Obstacle Interaction"), tr("mode:"), interactions, 0, false, &ok);
    
    QStringList obstacle_modes;
    obstacle_modes <<tr("Random") <<tr("Grid") <<tr("Circle");
    this->obstacle_mode = QInputDialog::getItem(this, tr("Obstacle Placement"), tr("mode:"), obstacle_modes, 0, false, &ok);
    
    double row_dist = QInputDialog::getDouble(this, "Numbers", "Dist between obstacles", .3, .001, 100000, 4, &ok);
    per_row = QInputDialog::getInt(this, "Numbers", "Number of Obstacles per row", 4, 1, 100, 1, &ok);
    
    if (!ok) return;

    QStringList status_modes;
    status_modes << mode << interaction;
    QString string_statuss = status_modes.join(",");
    statusBar()->showMessage(string_statuss);
    
    viewer->setObstacleRadius(OBSTACLE_RADIUS);

    /**
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Variables"));
    
       // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;

    QLineEdit *lineEdit = new QLineEdit(&dialog);
    QString label = QString("Particles");
    form.addRow(label, lineEdit);
    fields << lineEdit;
    QLineEdit *lineEditt = new QLineEdit(&dialog);
    QString labell = QString("Obstacles");
    form.addRow(labell, lineEditt);
    QString textt = lineEditt->text();
    int np = textt.toInt();

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QPushButton *button1 = new QPushButton("hello");

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::RestoreDefaults,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        foreach(QLineEdit * lineEdit, fields) {
            qDebug() << lineEdit->text();
        }
    }
    **/
    viewer->generate_particles(np);
    viewer->generate_obstacles(nob, obstacle_mode, row_dist, per_row);
    viewer->touch(interaction, OBSTACLE_RADIUS);
    viewer->repaint();

    //Start moving the circles since by default this is off
    isMovingParticles = true;
}

void MainWindow::default_values()
{
    int np = 1000;
    int nob = 10;
    max_runtime = 200000;
    double row_dist = 0;
    per_row = 0;
    OBSTACLE_RADIUS = 0.06;
    //PARTICLE_RADIUS = .01;
    //OBSTACLE_RADIUS = .06;
    mode = "Discrete";
    obstacle_mode = "Random";
    interaction = "Disappear";
    viewer->generate_particles(np);
    viewer->generate_obstacles(nob, obstacle_mode, row_dist, per_row);
    viewer->touch(interaction, OBSTACLE_RADIUS);
    viewer->repaint();

    //Start moving the circles since by default this is off
    isMovingParticles = true;
}
void MainWindow::restart()

{
    time_counter = 0;
    isMovingParticles = false;
    on_actionRandom_Circles_triggered();
}

void MainWindow::bin_count_window()
{
    pause();
    bool ok;
    BIN_COUNT = QInputDialog::getInt(this, "Number of bins", "#:", 10, 1, 1000, 1, &ok);
    if (!ok) return;
    play();
}

void MainWindow::on_actionCircles_toggled()
{
    viewer->toggle_circles();
    viewer->repaint();
    
    //Toggle them off so we aren't repainting when no circles are visible
    isMovingParticles = !isMovingParticles;
}

void MainWindow::timer_update()
{   

    // If we are moving the circles currently, then call random_walk_circles
    // to make them move!
    if (isMovingParticles){
        viewer->random_walk_particles(mode, WIND_DIST_X, WIND_DIST_Y);
        viewer->touch(interaction, OBSTACLE_RADIUS);
        viewer->repaint();
        time_counter+=(TIMER_INTERVAL);
        string_time = QString::number(time_counter);
        timetime->setPlainText(string_time);
        if (isMovingObstacles == true)
        {
            viewer->oscillate_obstacles(oscillation_mode, per_row, amplitude);
        }
        if (time_counter/1000.0 >= max_runtime || viewer->run_complete())
        {
            isMovingParticles = false;
            QMessageBox::information(0, QString("Notification"), QString("run complete!"), QMessageBox::Ok);
        }
    }
}