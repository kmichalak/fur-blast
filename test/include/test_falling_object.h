#ifndef FUR_BLAST_TEST_FALLING_OBJECT_H
#define FUR_BLAST_TEST_FALLING_OBJECT_H

#include <gtest/gtest.h>
#include "falling_object.h"

class FallingObjectDecorator : public FallingObject {
  public:
   float getVelocity() {
     return this->velocity;
   }

   float getUpVelocity() {
    return this->upVelocity;
   }

   bool hitBottomEnd() {
     return false;
   }

   void moveDown(float moveSpeed) {
    // do nothing
   }
};

class FallingObjectTest : public testing::Test {
  protected:
   void SetUp();
   void TearDown();
};

#endif //FUR_BLAST_TEST_FALLING_OBJECT_H
