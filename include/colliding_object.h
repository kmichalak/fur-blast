#ifndef FUR_BLAST_COLLIDING_OBJECT_H
#define FUR_BLAST_COLLIDING_OBJECT_H

#include "rectangle.h"
#include "game_object.h"

// TODO: Add bottom, top, left and right to make it easier to use
// object boundaries. Introducing bottom and right will reduce number of
// calculations needed by collisions detection mechanism.

class CollidingObject : public GameObject {
public:
    CollidingObject(int x, int y, int w, int h);
    virtual ~CollidingObject();
    virtual bool collidesRight(Rectangle *collidingObjectBoundaries);
    virtual bool collidesLeft(Rectangle *collidingObjectBoundaries);
    virtual bool collidesTop(Rectangle *collidingObjectBoundaries);
    virtual bool collidesBottom(Rectangle *collidingObjectBoundaries);
    Rectangle *getBoundaries();

private:
    bool inHorizontalBoundariesOf(Rectangle *collidingObjectBoundaries);
};

#endif //FUR_BLAST_COLLIDING_OBJECT_H
