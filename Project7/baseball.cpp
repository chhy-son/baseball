#include<iostream>

using namespace std;

struct GuessReuslt {
    int strikes;
    int balls;
    bool isSolved;
};

class BaseBallGame {
public:
    BaseBallGame(string answerNumber) : answerNumber{ answerNumber } 
    {

    }

    GuessReuslt guess(const string& guessNumber) {
        assertIllegalArguments(guessNumber);
        GuessReuslt gr = { 0, 0, false };

        for (int i = 0; i < 3; i++) {
            if (guessNumber[i] == answerNumber[i])
                gr.strikes++;
        
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (guessNumber[i] == answerNumber[j])
                    gr.balls++;
            }
        }
        
        if (gr.strikes == 3) gr.isSolved = true;

        return gr;
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
    string answerNumber;
};