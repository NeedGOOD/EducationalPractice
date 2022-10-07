#include <iostream>

int main() {
    int a = 5;

    int *px = &a;

    std::cout << "px = " << px << '\n';
    return 0;
}