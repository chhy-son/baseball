#include "pch.h"
#include "../Project7/baseball.cpp"

class BascBallGameExceptionFixture : public testing::Test {
public:
    void assertException(const string& guessNumber) {
        try {
            bb.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            //pass
        }
    }
private:
    BaseBallGame bb;
};

TEST_F(BascBallGameExceptionFixture, ThrowExceptionWhenInvalidCase) {
    assertException("12");
    assertException("12s");
    //duplicated num
    assertException("121");
    assertException("221");
    assertException("322");

}
