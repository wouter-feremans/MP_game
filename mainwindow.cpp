#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world.h"
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    QGraphicsScene * scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    auto world = new World();
    std::vector<std::unique_ptr<Tile>>tiles = world->createWorld("/home/wouter/Desktop/Media_processing/worldmap4.png");

    float displaySize = 2.0f;

    for(ulong i = 0; i < tiles.size();i++){
            auto & tile = tiles.at(i);
            QBrush brush(Qt::white);
            QPen pen(Qt::black);
            pen.setWidth(0);
            if(tile->getValue()>1){
                brush.setColor(Qt::black);
                pen.setColor(Qt::black);
            } else {
                brush.setColor(QColor(tile->getValue()*255,tile->getValue()*255,tile->getValue()*255));
                pen.setColor(QColor(tile->getValue()*255,tile->getValue()*255,tile->getValue()*255));
            }
            scene->addRect(tiles[i]->getXPos()*displaySize, tiles[i]->getYPos()*displaySize, displaySize, displaySize,pen,brush);
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}
