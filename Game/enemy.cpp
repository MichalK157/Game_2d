#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "player.h"
#include <typeinfo>



Enemy::Enemy():QObject(),QGraphicsRectItem()
{
    int rn = rand() % 700;
    setPos(rn,0);

    setRect(0,0,50,50);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);
}

void Enemy::move()
{
    QList<QGraphicsItem *>  colliding_items = collidingItems();
    for(int i = 0,n = colliding_items.size() ; i < n ; i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            exit(1);
        }
    }
    setPos(x(),y()+5 );
    if (pos().y()+rect().height()>600){
        scene()->removeItem(this);
        delete this;
    }
}
