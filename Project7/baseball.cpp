#include<iostream>

using namespace std;

class BaseBallGame {
public:
    void guess(const string& guessNumber) {
        assertIllegalArguments(guessNumber);
    }

    void assertIllegalArguments(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3)
            throw length_error("Must be three letters");
    
        for (char c : guessNumber) {
            if ('0' <= c && c <= '9')
                throw invalid_argument("Must be number");
        }

        if (isDuplicatedNum(guessNumber))
            throw invalid_argument("Not allow duplicated number");
    }
    bool isDuplicatedNum(const std::string& guessNumber)
    {
        return guessNumber[0] == guessNumber[1]
            || guessNumber[0] == guessNumber[2]
            || guessNumber[1] == guessNumber[2];
    }
};