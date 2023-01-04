#include <iostream>
#include <array>

std::array<long, 41> arr = {0, 1, };

int main() {

    /* memoization fibonacci */
    for (int i = 2; i < 41; i++) {
        arr.at(i) = arr.at(i-1) + arr.at(i-2);
    }

    /* input number of testcase : line */
    int line = 0;
    std::cin >> line;

    /* input : fibonacci number */
    int input = 0;
    for(int i = 0; i < line; i++) {
        std::cin >> input;

        if (input == 0) {
            std::cout << "1 0" << std::endl;
        } else if (input == 1) {
            std::cout << "0 1" << std::endl;    
        } else {
            std::cout << arr.at(input-1) << " " << arr.at(input) << std::endl;
        }
    }
}
