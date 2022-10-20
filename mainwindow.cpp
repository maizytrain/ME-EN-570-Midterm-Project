#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include <QGraphicsTextItem>
#include "antVisuals.h"
#include "colonyVisuals.h"
//#include "piestimator.cpp"

MainWindow::MainWindow(QWidget *parent) :QMainWindow{parent}, mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);

    connect(mMainWindowUI->actionExit, SIGNAL(triggered()), this, SLOT(actionExit_triggered()));
    //connect(mMainWindowUI->pushButton, SIGNAL(released()), this, SLOT(released()));

    mScene = new QGraphicsScene();
    mView = mMainWindowUI->graphicsView;

    mScene->setSceneRect(0,0,1250,650);

    mView->setScene(mScene);
    DrawScene();

}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
    delete mScene;
    delete mView;
}

void MainWindow::actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::Update() {

}



void MainWindow::DrawScene()
{

    QPixmap background(":/images/Ground_Dirt_007_basecolor_lighter.jpg");
    int xMaps{5};
    int yMaps{4};

    QGraphicsPixmapItem* backgroundItem [5][4];
    for (int i{0}; i < xMaps; i++)
    {
        for (int j{0}; j < yMaps; j++)
        {
            backgroundItem[i][j] = mScene->addPixmap(background);
            backgroundItem[i][j]->setScale(.25);
            backgroundItem[i][j]->setPos(i*256,j*256);
        }
    }

    mView->ensureVisible(0,0,1280,1024);

}

void MainWindow::ClearPoints()
{
    mScene->clear();
    DrawScene();
}

void MainWindow::DrawColony(colonyVisual& colony)
{
    colony.mPixitem = mScene->addPixmap(*colony.mPixmap);
}

void MainWindow::DrawAnt(antVisual& currentAnt)
{
    currentAnt.mPixItem = mScene->addPixmap(*currentAnt.mPixmap);
}

/*void MainWindow::released()
{
    DrawPoints();
}*/
