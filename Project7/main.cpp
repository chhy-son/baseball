#include<iostream>

int go(int a, int b) {
    if (a < 0 || b < 0)
        throw std::invalid_argument("under 0");
    if (a > 10 || b > 10)
        throw std::exception("over 10");
    return a + b;
}

int main() {
    try {
        std::cout << go(10, 10) << std::endl;
        std::cout << go(100, 10) << std::endl;
        std::cout << go(-1, 10) << std::endl;
    }
    catch (std::invalid_argument& err) {
        std::cout << err.what() << std::endl;
    }
    catch (std::exception& err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}