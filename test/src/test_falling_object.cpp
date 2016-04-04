#include "test_falling_object.h"

#include "falling_object.h"

void FallingObjectTest::SetUp() { }

void FallingObjectTest::TearDown() { }

TEST(FallingObjectTest, VelocityIsEqualInitialThrowingVelocityWhenThrowingUp) {
  // given
  FallingObjectDecorator *object = new FallingObjectDecorator();

  // when
  object->throwUp();
  object->update(0);

  // then
  EXPECT_EQ(INITIAL_UP_VELOCITY, object->getUpVelocity());
  delete object;
}

TEST(FallingObjectTest, VelocityChangesInTime) {
  // given
  FallingObjectDecorator *object = new FallingObjectDecorator();
  float expectedZeroVelocityTimeDelta = object->getUpVelocity() / float(GRAVITY_ACCELERATION);

  // when
  object->throwUp();
  object->update(0);
  object->update(expectedZeroVelocityTimeDelta * 10);

  // then
  EXPECT_EQ(object->getUpVelocity(), 0);
  delete object;
}

TEST(FallingObjectTest, VelocityVectorIsFacingUpwards) {
  // given
  FallingObjectDecorator *object = new FallingObjectDecorator();
  float expectedZeroVelocityTimeDelta = object->getUpVelocity() / float(GRAVITY_ACCELERATION);

  // when
  object->throwUp();
  object->update(expectedZeroVelocityTimeDelta / 2);

  // then
  EXPECT_TRUE(object->getVelocity() < 0);
}