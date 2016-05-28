#include "test_colliding_object_left_collision.h"

void CollidingObjectLeftCollisionTest::SetUp() { }

void CollidingObjectLeftCollisionTest::TearDown() { }

// ....................................
// .........ttt........................
// .........ttt........................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsCloseToLeftUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);

}

// ....................................
// ............ttt.....................
// ............ttt.....................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectStandsOnCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);

}

// ....................................
// ...............ttt..................
// ...............ttt..................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsCloseToRightUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height - 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);

}

// ....................................
// ....................................
// ....................................
// .........tttccc.....................
// .........tttccc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsCloseToTheLeftOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....................................
// ....................................
// ............tct.....................
// ............ctc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionDetectedWhenObjectLaysOnTheCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_TRUE(isColliding);

}

// ....................................
// ...(a pixel next to the pixel)......
// ....................................
// .........cccttt.....................
// .........cccttt.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionDetectedWhenObjectIsCloseToTheRightOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....................................
// ....................................
// .........cccttt.....................
// .........cccttt.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionDetectedWhenObjectTouchesTheRightSideOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_TRUE(isColliding);
}

// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// .........ttt........................
// .........ttt........................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsCloseToLeftLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);

}

// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ............ttt.....................
// ............ttt.....................
// ....................................
TEST(CollidingObject, LeftCollisionDetectedWhenCollidingObjectStandsOnTestedObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);

}

// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ...............ttt..................
// ...............ttt..................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsCloseToRightLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height + 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);

}


// ....................................
// .......ttt..........................
// .......ttt..........................
// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsOverAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ............ttt.....................
// ............ttt.....................
// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsDirectlyOverCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// .................ttt................
// .................ttt................
// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsOverAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....................................
// ....................................
// ....................................
// ....................................
// ............ttt..ccc................
// ............ttt..ccc................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....................................
// ....................................
// ....................................
// ....................................
// ............ccc..ttt................
// ............ccc..ttt................
// ....................................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}


// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
// .......ttt..........................
// .......ttt..........................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsUnderAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
// ............ttt.....................
// ............ttt.....................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsDirectlyUnderTheCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
// .................ttt................
// .................ttt................
// ....................................
TEST(CollidingObject, LeftCollisionNotDetectedWhenObjectIsUnderAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesLeft(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}
