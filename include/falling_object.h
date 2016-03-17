#ifndef FUR_BLAST_FALLING_OBJECT_H
#define FUR_BLAST_FALLING_OBJECT_H

#include "game_object.h"

class FallingObject : public GameObject {
  public:
   FallingObject();
   virtual ~FallingObject();
   void update(float dt);

  void throwUp(float dt);

  private:
   float acceleration = 0.1;
   float throwUpAcceleration = 0.1;
   float velocity = 1.0;
   float upVelocity = 0;

};

#endif //FUR_BLAST_FALLING_OBJECT_H
