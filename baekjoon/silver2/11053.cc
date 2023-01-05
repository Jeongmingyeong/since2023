#include <iostream>
#include <array>
#define MAX 1000

int Max (int A, int B) {
    return A > B ? A : B;
}

int main() {
    int result = 0;
    int N = 0; /* size of sequence */
    std::array<int, MAX> arr; /* sequence */
    std::array<int, MAX> LIS; /* Longest Increasing Subsequence */

    std::cin >> N;

    /* store number in sequence */
    for(int i = 0; i < N; i++) {
        std::cin >> arr.at(i);
    }

    /* iterate to find LIS */
    for(int i = 0; i < N; i++) {
        LIS.at(i) = 1;
        for(int j = 0; j < i; j++) {
            if(arr.at(j) < arr.at(i)) {
                LIS.at(i) = Max(LIS.at(i), LIS.at(j)+1);
            }
        }

        result = Max(LIS.at(i), result);
    }

    std::cout << result << std::endl;
}
