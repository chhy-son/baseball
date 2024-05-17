#include<iostream>

using namespace std;

class BaseBallGame {
public:
    bool guess(const string& str) {
        if (str.length() != 3)
            throw length_error("Must be three letters");
        for (char c : str) {
            if (c < '0' || c >'9')
                throw invalid_argument("Must be number");
        }
    }
};