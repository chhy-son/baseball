#include "pch.h"
#include "../Project7/baseball.cpp"

TEST(BaseBallGameTest, ExceptionTest) {
    BaseBallGame bb;

    EXPECT_THROW(bb.guess("12"), length_error);

}