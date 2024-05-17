#include "pch.h"
#include "../Project7/baseball.cpp"

class BascBallGameExceptionFixture : public testing::Test {
public:
    void assertException(const string& guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            //pass
        }
    }
    BaseBallGame game{"123"};
};

TEST_F(BascBallGameExceptionFixture, ThrowExceptionWhenInvalidCase) {
    assertException("12");
    assertException("12s");
    //duplicated num
    assertException("121");
    assertException("221");
    assertException("322");
}

TEST_F(BascBallGameExceptionFixture, 3strike) {

    GuessReuslt res = game.guess("123");

    EXPECT_TRUE(res.isSolved);
    EXPECT_EQ(res.strikes, 3);
    EXPECT_EQ(res.balls, 3);
}
