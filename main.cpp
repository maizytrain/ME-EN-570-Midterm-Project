#include "mainwindow.h"
#include <QApplication>
#include "antVisuals.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  colonyVisual TestColony;
  w.DrawColony(TestColony);
  antVisual TestAnt;
  w.DrawAnt(TestAnt);

  return a.exec();
}


