#include <iostream>
#include <algorithm>

int main() {
    int N = 0; /* size of array */
    int sum = 0; /* store result */
    
    std::cin >> N;

    int A[N];
    int B[N];

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::sort(A, A+N);
    std::sort(B, B+N, std::greater<>());

    for(int i = 0; i < N; i++) {
        sum += (A[i] * B[i]);
    }

    std::cout << sum << std::endl;
    return 0;
}