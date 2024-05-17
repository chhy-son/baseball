#include "pch.h"
#include "../Project7/baseball.cpp"

class BascBallGameExceptionFixture : public testing::Test {
public:
    void assertException(const string& guessStr) {
        try {
            bb.guess(guessStr);
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
}
