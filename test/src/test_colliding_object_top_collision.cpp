#include "test_colliding_object_top_collision.h"

void CollidingObjectTopCollisionTest::SetUp() { }

void CollidingObjectTopCollisionTest::TearDown() { }

// ....................................
// .........ttt........................
// .........ttt........................
// ............ccc.....................
// ............ccc.....................
// ....................................
// ....................................
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsCloseToLeftUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectStandsOnCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsCloseToRightUpperCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height - 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsCloseToTheLeftOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width - 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionDetectedWhenObjectLaysOnTheCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsCloseToTheRightOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsCloseToLeftLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width + 1,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionDetectedWhenCollidingObjectStandsOnTestedObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

    // then
    EXPECT_TRUE(isColliding);

}

// ....................................
// ....................................
// ............ccc.....................
// ............ccc.....................
// ...............ttt..................
// ...............ttt..................
// ....................................
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsCloseToRightLowerCornerOfCollidingObject) {

    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height + 1,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );


    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsOverAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsDirectlyOverCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsOverAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y - collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsUnderAndToTheLeftOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x - collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsDirectlyUnderTheCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

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
TEST(CollidingObject, TopCollisionNotDetectedWhenObjectIsUnderAndToTheRightOfOCollidingObject) {
    // given
    CollidingObject *collidingObject = new CollidingObject(100, 100, 10, 10);
    CollidingObject *objectUnderTest = new CollidingObject(
            collidingObject->getBoundaries()->x + collidingObject->getBoundaries()->width * 2,
            collidingObject->getBoundaries()->y + collidingObject->getBoundaries()->height * 2,
            collidingObject->getBoundaries()->width,
            collidingObject->getBoundaries()->height
    );

    // when
    bool isColliding = objectUnderTest->collidesTop(collidingObject->getBoundaries());

    // then
    EXPECT_FALSE(isColliding);
}
