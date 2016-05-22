#ifndef FUR_BLAST_GAME_OBJECT_H
#define FUR_BLAST_GAME_OBJECT_H

#include "rectangle.h"

class GameObject {
public:
    GameObject();

    virtual ~GameObject();

    void setGameAreaBoundaries(Rectangle *boundaries);

    void setBoundaries(Rectangle *boundaries);

    bool isInGameAreaBoundaries();

//    virtual void moveLeft(float moveSpeed);
//
//    virtual void moveRight(float moveSpeed);
//
//    virtual void moveUp(float moveSpeed);
//
//    virtual void moveDown(float moveSpeed);

protected:
    virtual bool hitRightEnd();

    virtual bool hitLeftEnd();

    virtual bool hitTopEnd();

    virtual bool hitBottomEnd();

    Rectangle *boundaries;

private:
    Rectangle *gameArea;


};

#endif //FUR_BLAST_GAME_OBJECT_H
