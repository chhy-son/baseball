#include<iostream>

using namespace std;

struct GuessReuslt {
    int strikes;
    int balls;
    bool isSolved;
};

class BaseBallGame {
public:
    const int numbersLength = 3;
    BaseBallGame(string answerNumber) : answerNumbers{ answerNumber }
    {

    }

    GuessReuslt guess(const string& guessNumbers) {
        assertIllegalArguments(guessNumbers);
        GuessReuslt result = { 0, 0, false };

        for (int i = 0; i < numbersLength; i++) {
            if (isStrike(guessNumbers, i))
                result.strikes++;
            else if (isBall(guessNumbers[i]))
                result.balls++;
        }

        if (result.strikes == numbersLength)
            result.isSolved = true;

        return result;
    }

    bool isStrike(const string& guessNumbers, int i)
    {
        return guessNumbers[i] == answerNumbers[i];
    }
    bool isBall(char guessNumber)
    {
        for (char answerNumber : answerNumbers){
            if (guessNumber != answerNumber)
                continue;
            return true;
        }
        return false;
    }

    void assertIllegalArguments(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3)
            throw length_error("Must be three letters");

        for (char c : guessNumber) {
            if ('0' <= c && c <= '9')
                continue;
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
private:
    string answerNumbers;
};