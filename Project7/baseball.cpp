#include<iostream>

using namespace std;

class BaseBallGame {
public:
    bool guess(const string& str) {
        if (str.length() != 3)
            throw length_error("Must be three letters");
    }
};