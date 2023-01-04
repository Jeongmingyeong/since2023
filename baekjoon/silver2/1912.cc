#include <iostream>
#include <array>
#define MAX 100000

int Max (int A, int B) {
    return A > B ? A : B;
}

int main() {
    int N = 0; /* the number of input */
    int result = 0; /* max value */
    std::array<int, MAX> arr; /* input number */
    std::array<int, MAX> sum_max; /* store the maximum value of sum (DP) */
    std::cin >> N;

    /* store input number in array */
    for(int i = 0; i < N; i++) {
        std::cin >> arr.at(i);
    }

    /* memoization */
    sum_max.at(0) = arr.at(0); /* base case */
    result = sum_max.at(0); /* initialization */

    for(int i = 1; i < N; i++) {
        sum_max.at(i) = Max(arr.at(i), (sum_max.at(i-1) + arr.at(i)));
        if(result < sum_max.at(i)) { /* store max value */
            result = sum_max.at(i);
        }
    }

    std::cout << result << std::endl;
}
