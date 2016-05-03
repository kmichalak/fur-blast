#include "test_colliding_object.h"

void CollidingObjectTest::SetUp() { }

void CollidingObjectTest::TearDown() { }

TEST(CollidingObject, BottomCollisionDetectedWhenObjectStandsOnOtherObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(10, 10, 10, 10);
    CollidingObject *testingObject = new CollidingObject(
            int(collidingObject->getBoundaries()->x),
            int(collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height),
            int(collidingObject->getBoundaries()->width),
            int(collidingObject->getBoundaries()->height)
    );


    // when
    bool isColliding = testingObject->collidesBottom(collidingObject);

    // then
    EXPECT_TRUE(isColliding);

}

TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsOverAndNextToOtherObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(10, 10, 10, 10);
    CollidingObject *testingObject = new CollidingObject(
            int(collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1),
            int(collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height),
            int(collidingObject->getBoundaries()->width),
            int(collidingObject->getBoundaries()->height)
    );


    // when
    bool isColliding = testingObject->collidesBottom(collidingObject);

    // then
    EXPECT_FALSE(isColliding);
}

TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsUnderOtherObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(10, 10, 10, 10);
    CollidingObject *testingObject = new CollidingObject(
            int(collidingObject->getBoundaries()->x),
            int(collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height + 3),
            int(collidingObject->getBoundaries()->width),
            int(collidingObject->getBoundaries()->height)
    );


    // when
    bool isColliding = testingObject->collidesBottom(collidingObject);

    // then
    EXPECT_FALSE(isColliding);
}