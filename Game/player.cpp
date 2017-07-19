#include "player.h"
#include "shot.h"
#include "enemy.h"
#include <QGraphicsScene>

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x()+rect().width()<800)
        setPos(x()+10,y());
    }
    /* else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    } */
    else if (event->key() == Qt::Key_Space){
    Shot * s = new Shot();

    s->setPos(x(),y());
    scene()->addItem(s);

    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
