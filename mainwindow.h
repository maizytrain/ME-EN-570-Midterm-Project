#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QGraphicsScene>
#include <QPushButton>
#include "antVisuals.h"

namespace Ui {class MainWindowForm;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void DrawScene();
    void DrawColony();
    void DrawAnt(antVisual& currentAnt);

    void ClearPoints();

    QGraphicsScene* GiveScene();

public slots:
    void actionExit_triggered();
    //void released();

private:
    Ui::MainWindowForm *mMainWindowUI;
    QGraphicsScene *mScene;
    QGraphicsView *mView;

};

#endif // MAINWINDOW_H
