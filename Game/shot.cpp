#include "shot.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

Shot::Shot(){
    setRect(0,0,1,3);

    QTimer *timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(5);
}

void Shot::move()
{
    QList<QGraphicsItem *>  colliding_items = collidingItems();
    for(int i = 0,n = colliding_items.size() ; i < n ; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-rect().height());
    if (pos().y()+ rect().height() <0){
        scene()->removeItem(this);
        delete this;
    }
}
