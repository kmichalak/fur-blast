#ifndef FUR_BLAST_FALLING_OBJECT_H
#define FUR_BLAST_FALLING_OBJECT_H

#include <list>
#include "colliding_object.h"

#define GRAVITY_ACCELERATION 0.2
#define INITIAL_UP_VELOCITY 3

class FallingObject : public CollidingObject {
public:
    FallingObject(int x, int y, int w, int h);

    virtual ~FallingObject();

    void update(float dt, std::list<CollidingObject *> collidingObjects);

    void throwUp();

protected:
    float velocity = 1.0;
    float upVelocity = 0;

    bool thrownUp;
    float lastTimeDelta;
    bool isInAir;


};

#endif //FUR_BLAST_FALLING_OBJECT_H
