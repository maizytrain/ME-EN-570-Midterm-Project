#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include <QGraphicsTextItem>
//#include "piestimator.cpp"

MainWindow::MainWindow(QWidget *parent) :QMainWindow{parent}, mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);

    connect(mMainWindowUI->actionExit, SIGNAL(triggered()), this, SLOT(actionExit_triggered()));
    connect(mMainWindowUI->pushButton, SIGNAL(released()), this, SLOT(released()));

    mScene = new QGraphicsScene();
    mView = mMainWindowUI->graphicsView;
    mButton = mMainWindowUI->pushButton;

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



void MainWindow::DrawScene()
{
    //mScene->addRect(50,50,mScene->width(),mScene->height());
    QRect rect(0,0,500,500);
    mScene->addRect(rect);
    mScene->addEllipse(0,0,500,500);
    //mView->ensureVisible(rect);
}

void MainWindow::ClearPoints()
{
    mScene->clear();
    DrawScene();
}

double generate_random_double(double minValue, double maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(minValue, maxValue);
    return dis(gen);
}

void MainWindow::DrawPoints()
{
    ClearPoints();

    double bounds{500};
    double radius{bounds/2};
    int inCircle{0};

    int pointSize{10};

    int count = mMainWindowUI->countInput->value();

    QString outputString;

    if (count != 0)
    {

        for (int i{0}; i < count; i++)
        {
            int xSample = generate_random_double(0,bounds);
            int ySample = generate_random_double(0,bounds);

            double radiusSample = sqrt((xSample-radius) * (xSample-radius) + (ySample-radius) * (ySample-radius));

            if (radiusSample <= radius)
            {
                inCircle++;
            }

            mScene->addEllipse(xSample - pointSize / 2, ySample - pointSize / 2, pointSize, pointSize);

            double estimatedPi = 4 * double(inCircle) / double(count);

            outputString = QString::fromStdString("Your estimated value of Pi is: " + std::to_string(estimatedPi));
        }
    }
    else if (sillyCounter == 0)
    {
        outputString = QString::fromStdString("Don't be silly, I can't count zero points!");
    }
    else if (sillyCounter == 1)
    {
        outputString = QString::fromStdString("Clicking it twice won't change my mind.");
    }
    else if (sillyCounter == 2)
    {
        outputString = QString::fromStdString("Or three times...");
    }
    else if (sillyCounter == 3)
    {
        outputString = QString::fromStdString("Or four...");
    }
    else if (sillyCounter == 4)
    {
        outputString = QString::fromStdString("five...");
    }
    else if (sillyCounter < 10)
    {
        outputString = QString::fromStdString("...");
    }
    else if (sillyCounter < 15)
    {
        outputString = QString::fromStdString("Having Fun?");
    }
    else if (sillyCounter < 20)
    {
        outputString = QString::fromStdString("Because I built this whole program to do something else, and you're kind of using it for a purpose I don't understand.");
    }
    else if (sillyCounter < 25)
    {
        outputString = QString::fromStdString("Oh, I know what happened, my three year old daughter got on my computer and doesn't know how to read!");
    }
    else if (sillyCounter < 30)
    {
        outputString = QString::fromStdString("...");
    }
    else if (sillyCounter < 35)
    {
        outputString = QString::fromStdString("Okay, well if you feel like using the program any time soon I'll be here.");
    }
    else if (sillyCounter >= 35)
    {
        outputString = QString::fromStdString("...");
    }

    if (count == 0)
    {
        sillyCounter += 1;
    }

    mMainWindowUI->outputBox->setText(outputString);
}

void MainWindow::released()
{
    DrawPoints();
}
