#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);


   QGraphicsScene * scene = new QGraphicsScene();

   Player * player = new Player();
   player->setRect(0,0,10,10);

   scene->addItem(player);

   player->setFlag(QGraphicsItem::ItemIsFocusable);
   player->setFocus();

   QGraphicsView * view = new QGraphicsView(scene);

   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->show();
   view->setFixedSize(800,600);
   scene->setSceneRect(0,0,800,600);
   player->setPos(view->width()/2,view->height()-player->rect().height()-10);

   QTimer * timer = new QTimer();
   QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
   timer->start(2000);


   return a.exec();
}
