#include "mainwindow.h"
#include <QApplication>
#include "world.h"
#include <iostream>
#include <QImage>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.showFullScreen();
    return a.exec();
}


