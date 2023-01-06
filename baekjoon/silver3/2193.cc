#include <iostream>
#include <array>
#define MAX 91 /* Max length of number */

int main() {
    int size = 0; /* length of number */
    std::array<long, MAX> arr; /* n-digit pinary number */

    std::cin >> size;

    arr.at(1) = 1;
    arr.at(2) = 1;
    for(int i = 3; i <= size; i++) {
        arr.at(i) = arr.at(i-1) + arr.at(i-2);
    }

    std::cout << arr.at(size) << std::endl;
    return 0;
}
