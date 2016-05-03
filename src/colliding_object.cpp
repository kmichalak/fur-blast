#include "colliding_object.h"

CollidingObject::CollidingObject(int x, int y, int w, int h) {

    this->boundaries = new Rectangle(x, y, w, h);
}

CollidingObject::~CollidingObject() {
    delete this->boundaries;
}


bool CollidingObject::collidesRight(CollidingObject *object) {
    int rightEdgePosition = int(this->getBoundaries()->x + this->getBoundaries()->width);
    return object->getBoundaries()->x <= rightEdgePosition;
}

bool CollidingObject::collidesLeft(CollidingObject *object) {
    int objectRightEdgePosition = int(object->getBoundaries()->x + object->getBoundaries()->width);
    return objectRightEdgePosition >= this->getBoundaries()->x;
}

bool CollidingObject::collidesTop(CollidingObject *object) {
    float objectBottomEdgePosition = int(object->getBoundaries()->y + object->getBoundaries()->height);
    return this->getBoundaries()->y <= objectBottomEdgePosition;
}

bool CollidingObject::collidesBottom(CollidingObject *object) {
    int bottomEdgePosition = int(this->getBoundaries()->y + this->getBoundaries()->height);
    return bottomEdgePosition == object->getBoundaries()->y
           && inHorizontalBoundariesOf(object);
}

Rectangle *CollidingObject::getBoundaries() {
    return this->boundaries;
}

bool CollidingObject::inHorizontalBoundariesOf(CollidingObject *object) {
    Rectangle *collidingObjectBoundaries = object->getBoundaries();
    float collidingObjectRightEdgePosition = collidingObjectBoundaries->x + collidingObjectBoundaries->width;
    float itsRightEdgePosition = this->getBoundaries()->x + this->getBoundaries()->width;

    return (this->getBoundaries()->x >= collidingObjectBoundaries->x
           && this->getBoundaries()->x <= collidingObjectRightEdgePosition)
            || (itsRightEdgePosition >= collidingObjectBoundaries->x
                          && itsRightEdgePosition <= collidingObjectRightEdgePosition);
}
