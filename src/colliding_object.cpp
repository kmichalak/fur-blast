#include "colliding_object.h"

CollidingObject::CollidingObject(int x, int y, int w, int h) {

    this->boundaries = new Rectangle(x, y, w, h);
}

CollidingObject::~CollidingObject() {
    delete this->boundaries;
}


bool CollidingObject::collidesRight(CollidingObject *object) {
    int rightEdgePosition = int(this->getBoundaries()->x + this->getBoundaries()->width);
    return object->getBoundaries()->x <= rightEdgePosition
           && object->getBoundaries()->x + object->getBoundaries()->width > this->getBoundaries()->x
           && this->getBoundaries()->y + this->getBoundaries()->height > object->getBoundaries()->y
           && this->getBoundaries()->y < object->getBoundaries()->y + object->getBoundaries()->height;
}

bool CollidingObject::collidesLeft(CollidingObject *object) {
    int objectRightEdgePosition = int(object->getBoundaries()->x + object->getBoundaries()->width);
    return objectRightEdgePosition >= this->getBoundaries()->x
           && object->getBoundaries()->x < this->getBoundaries()->x + this->getBoundaries()->width
           && this->getBoundaries()->y + this->getBoundaries()->height > object->getBoundaries()->y
           && this->getBoundaries()->y < object->getBoundaries()->y + object->getBoundaries()->height;
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
