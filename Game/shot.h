#ifndef SHOT
#define SHOT

#include <QGraphicsRectItem>
#include<QObject>

class Shot:public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Shot();
    public slots:
    void move();
};



#endif // SHOT

