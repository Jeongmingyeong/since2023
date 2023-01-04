#include <iostream>
#include <array>
#include <vector>
#define MAX 300 /* Maximum number of stair */

/* return Max value */
int Max (int A, int B) {
    return A > B ? A : B;
}

int main() {
    int result = 0; /* max point */
    std::array<int, MAX> input; /* stair's point */
    std::array<int, MAX> maximum; /* Nth maximum value */
    int stair_number = 0;
    std::cin >> stair_number;

    /* input the stair's point */
    for(int i = 0; i < stair_number; i++) {
        std::cin >> input.at(i);
    }

    /* memoization max value */
    maximum.at(0) = input.at(0);
    maximum.at(1) = input.at(0) + input.at(1);
    maximum.at(2) = Max(
        (input.at(0) + input.at(2)),
        (input.at(1) + input.at(2))
    );

    for(int i = 3; i < stair_number; i++) {
        maximum.at(i) = Max(
            (maximum.at(i-2) + input.at(i)),
            (maximum.at(i-3) + input.at(i-1) + input.at(i))
        );
    }

    std::cout << maximum.at(stair_number-1) << std::endl;
}
