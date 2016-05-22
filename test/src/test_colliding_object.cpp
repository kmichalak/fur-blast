#include "test_colliding_object.h"

void CollidingObjectTest::SetUp() { }

void CollidingObjectTest::TearDown() { }

// ....................................
// .........ttt........................
// .........ttt........................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsCloseToLeftUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionDetectedWhenObjectStandsOnCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

    // then
    EXPECT_TRUE(isColliding);

}

// ....................................
// ...............ttt..................
// ...............ttt..................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsCloseToRightUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height - 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsCloseToTheLeftOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionDetectedWhenObjectLaysOnTheCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsCloseToTheRightOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}

// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// .........ttt........................
// .........ttt........................
// ....................................
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsCloseToLeftLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenCollidingObjectStandsOnTestedObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsCloseToRightLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height + 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsOverAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsDirectlyOverCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsOverAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsUnderAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsDirectlyUnderTheCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

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
TEST(CollidingObject, BottomCollisionNotDetectedWhenObjectIsUnderAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesBottom(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}
