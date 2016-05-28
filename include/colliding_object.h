#ifndef FUR_BLAST_COLLIDING_OBJECT_H
#define FUR_BLAST_COLLIDING_OBJECT_H

#include "rectangle.h"
#include "game_object.h"

class CollidingObject : public GameObject {
public:
    CollidingObject(int x, int y, int w, int h);
    virtual ~CollidingObject();
    virtual bool collidesRight(Rectangle *collidingObjectBoundaries);
    virtual bool collidesLeft(Rectangle *collidingObjectBoundaries);
    virtual bool collidesTop(Rectangle *collidingObjectBoundaries);
    virtual bool collidesBottom(Rectangle *collidingObjectBoundaries);
    Rectangle *getBoundaries();

    int getTop();
    int getRight();
    int getBottom();
    int getLeft();

private:
    bool inHorizontalBoundariesOf(Rectangle *collidingObjectBoundaries);
};

#endif //FUR_BLAST_COLLIDING_OBJECT_H
