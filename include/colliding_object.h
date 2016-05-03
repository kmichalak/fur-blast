#ifndef FUR_BLAST_COLLIDING_OBJECT_H
#define FUR_BLAST_COLLIDING_OBJECT_H

#include "rectangle.h"
#include "game_object.h"

class CollidingObject : public GameObject {
public:
    CollidingObject(int x, int y, int w, int h);
    virtual ~CollidingObject();
    virtual bool collidesRight(CollidingObject *object);
    virtual bool collidesLeft(CollidingObject *object);
    virtual bool collidesTop(CollidingObject *object);
    virtual bool collidesBottom(CollidingObject *object);
    Rectangle *getBoundaries();

    bool inHorizontalBoundariesOf(CollidingObject *pObject);
};

#endif //FUR_BLAST_COLLIDING_OBJECT_H
