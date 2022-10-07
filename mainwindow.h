#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QGraphicsScene>
#include <QPushButton>

namespace Ui {class MainWindowForm;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void DrawScene();
    void DrawPoints();

    void ClearPoints();

public slots:
    void actionExit_triggered();
    void released();

private:
    Ui::MainWindowForm *mMainWindowUI;
    QGraphicsScene *mScene;
    QGraphicsView *mView;
    QPushButton *mButton;
    int sillyCounter{0};
};

#endif // MAINWINDOW_H
