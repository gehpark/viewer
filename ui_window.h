/********************************************************************************
 ** Form generated from reading UI file 'window.ui'
 **
 ** Created: Tue Jul 16 00:52:05 2013
 **      by: Qt User Interface Compiler version 4.8.4
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "glviewer.h"

#include <iostream>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRandom_Circles;
    QAction *actionCircles;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    GlViewer *viewer;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuData;
    QMenu *menuView;
    
    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(676, 572);
        actionRandom_Circles = new QAction(MainWindow);
        actionRandom_Circles->setObjectName(QString::fromUtf8("actionRandom_Circles"));
        actionCircles = new QAction(MainWindow);
        actionCircles->setObjectName(QString::fromUtf8("actionCircles"));
        actionCircles->setCheckable(true);
        actionCircles->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        viewer = new GlViewer(centralwidget);
        viewer->setObjectName(QString::fromUtf8("viewer"));
        viewer->setFocusPolicy(Qt::StrongFocus);
        viewer->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        pushButton = new QPushButton(viewer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 114, 32));
        
        gridLayout->addWidget(viewer, 0, 0, 1, 1);
        
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 676, 22));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        
        menuBar->addAction(menuData->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuData->addAction(actionRandom_Circles);
        menuView->addAction(actionCircles);
        
        retranslateUi(MainWindow);
        
        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi
    
    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Random Walk", 0, QApplication::UnicodeUTF8));
        actionRandom_Circles->setText(QApplication::translate("MainWindow", "Random Circles", 0, QApplication::UnicodeUTF8));
        actionRandom_Circles->setShortcut(QApplication::translate("MainWindow", "I", 0, QApplication::UnicodeUTF8));
        actionCircles->setText(QApplication::translate("MainWindow", "Circles", 0, QApplication::UnicodeUTF8));
        actionCircles->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        menuData->setTitle(QApplication::translate("MainWindow", "Data", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi
    
};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
