#include "test_colliding_object_right_collision.h"

void CollidingObjectRightCollisionTest::SetUp() { }

void CollidingObjectRightCollisionTest::TearDown() { }

// ....................................
// .........ttt........................
// .........ttt........................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsCloseToLeftUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectStandsOnCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsCloseToRightUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height - 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsCloseToTheRightOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionDetectedWhenObjectLaysOnTheCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

    // then
    EXPECT_TRUE(isColliding);

}

// ....................................
// ....................................
// ....................................
// .........cccttt.....................
// .........cccttt.....................
// ....................................
// ....................................
TEST(CollidingObject, RightCollisionDetectedWhenObjectIsCloseToTheRightSideOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....(a pixel next to the pixel).....
// ....................................
// .........cccttt.....................
// .........cccttt.....................
// ....................................
// ....................................
TEST(CollidingObject, RightCollisionDetectedWhenObjectTouchesTheRightSideOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsCloseToLeftLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionDetectedWhenCollidingObjectStandsOnTestedObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsCloseToRightLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height + 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsOverAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsDirectlyOverCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsOverAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsUnderAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsDirectlyUnderTheCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

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
TEST(CollidingObject, RightCollisionNotDetectedWhenObjectIsUnderAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesRight(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}
