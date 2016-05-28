#include "colliding_object.h"

CollidingObject::CollidingObject(int x, int y, int w, int h) {

    this->boundaries = new Rectangle(x, y, w, h);
}

CollidingObject::~CollidingObject() {
    delete this->boundaries;
}


bool CollidingObject::collidesRight(Rectangle *collidingObjectBoundaries) {
    int rightEdgePosition = this->getRight();
    return collidingObjectBoundaries->x <= rightEdgePosition
           && collidingObjectBoundaries->x + collidingObjectBoundaries->width > this->getBoundaries()->x
           && this->getBottom() > collidingObjectBoundaries->y
           && this->getTop() < collidingObjectBoundaries->y + collidingObjectBoundaries->height;
}

bool CollidingObject::collidesLeft(Rectangle *collidingObjectBoundaries) {
    int objectRightEdgePosition = collidingObjectBoundaries->x + collidingObjectBoundaries->width;
    return objectRightEdgePosition >= this->getLeft()
           && collidingObjectBoundaries->x <= this->getRight()
           && this->getBottom() > collidingObjectBoundaries->y
           && this->getTop() < collidingObjectBoundaries->y + collidingObjectBoundaries->height;
}

bool CollidingObject::collidesTop(Rectangle *collidingObjectBoundaries) {
    float objectBottomEdgePosition = collidingObjectBoundaries->y + collidingObjectBoundaries->height;
    return this->getTop() <= objectBottomEdgePosition
           && this->getBottom() >= objectBottomEdgePosition
           && inHorizontalBoundariesOf(collidingObjectBoundaries);
}

bool CollidingObject::collidesBottom(Rectangle *collidingObjectBoundaries) {
    return this->getBottom() >= collidingObjectBoundaries->y
           && this->getTop() <= collidingObjectBoundaries->y
           && inHorizontalBoundariesOf(collidingObjectBoundaries);
}

Rectangle *CollidingObject::getBoundaries() {
    return this->boundaries;
}

bool CollidingObject::inHorizontalBoundariesOf(Rectangle *collidingObjectBoundaries) {
    float collidingObjectRightEdgePosition = collidingObjectBoundaries->x + collidingObjectBoundaries->width;
    float itsRightEdgePosition = this->getBoundaries()->x + this->getBoundaries()->width;

    return (this->getLeft() >= collidingObjectBoundaries->x
            && this->getLeft() <= collidingObjectRightEdgePosition)
           || (itsRightEdgePosition >= collidingObjectBoundaries->x
               && itsRightEdgePosition <= collidingObjectRightEdgePosition);
}

int CollidingObject::getTop() {
    return this->boundaries->y;
}

int CollidingObject::getRight() {
    return this->boundaries->x + this->boundaries->width;
}

int CollidingObject::getBottom() {
    return this->boundaries->y + this->boundaries->height;
}

int CollidingObject::getLeft() {
    return this->boundaries->x;
}
