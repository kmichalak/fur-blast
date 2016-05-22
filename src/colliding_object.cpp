#include "colliding_object.h"

CollidingObject::CollidingObject(int x, int y, int w, int h) {

    this->boundaries = new Rectangle(x, y, w, h);
}

CollidingObject::~CollidingObject() {
    delete this->boundaries;
}


bool CollidingObject::collidesRight(Rectangle *collidingObjectBoundaries) {
    int rightEdgePosition = int(this->getBoundaries()->x + this->getBoundaries()->width);
    return collidingObjectBoundaries->x <= rightEdgePosition
           && collidingObjectBoundaries->x + collidingObjectBoundaries->width > this->getBoundaries()->x
           && this->getBoundaries()->y + this->getBoundaries()->height > collidingObjectBoundaries->y
           && this->getBoundaries()->y < collidingObjectBoundaries->y + collidingObjectBoundaries->height;
}

bool CollidingObject::collidesLeft(Rectangle *collidingObjectBoundaries) {
    int objectRightEdgePosition = int(collidingObjectBoundaries->x + collidingObjectBoundaries->width);
    return objectRightEdgePosition >= this->getBoundaries()->x
           && collidingObjectBoundaries->x <= this->getBoundaries()->x + this->getBoundaries()->width
           && this->getBoundaries()->y + this->getBoundaries()->height > collidingObjectBoundaries->y
           && this->getBoundaries()->y < collidingObjectBoundaries->y + collidingObjectBoundaries->height;
}

bool CollidingObject::collidesTop(Rectangle *collidingObjectBoundaries) {
    float objectBottomEdgePosition = int(collidingObjectBoundaries->y + collidingObjectBoundaries->height);
    return this->getBoundaries()->y <= objectBottomEdgePosition
           && this->getBoundaries()->y + this->getBoundaries()->height > objectBottomEdgePosition
           && inHorizontalBoundariesOf(collidingObjectBoundaries);
}

bool CollidingObject::collidesBottom(Rectangle *collidingObjectBoundaries) {
    int bottomEdgePosition = int(this->getBoundaries()->y + this->getBoundaries()->height);
    return bottomEdgePosition >= collidingObjectBoundaries->y
           && this->getBoundaries()->y < collidingObjectBoundaries->y
           && inHorizontalBoundariesOf(collidingObjectBoundaries);
}

Rectangle *CollidingObject::getBoundaries() {
    return this->boundaries;
}

bool CollidingObject::inHorizontalBoundariesOf(Rectangle *collidingObjectBoundaries) {
    float collidingObjectRightEdgePosition = collidingObjectBoundaries->x + collidingObjectBoundaries->width;
    float itsRightEdgePosition = this->getBoundaries()->x + this->getBoundaries()->width;

    return (this->getBoundaries()->x >= collidingObjectBoundaries->x
            && this->getBoundaries()->x <= collidingObjectRightEdgePosition)
           || (itsRightEdgePosition >= collidingObjectBoundaries->x
               && itsRightEdgePosition <= collidingObjectRightEdgePosition);
}
