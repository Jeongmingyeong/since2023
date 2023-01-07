#include <iostream>
#include <array>
#define MAX 1001

int Min(int A, int B) {
    return A < B ? A : B;
}

/* solution 1 : check odd or even */
int Sol1() {
    int N = 0; /* the number of stone */

    std::cin >> N;

    if(N % 2 == 0) { 
        std::cout << "CY" << std::endl;
    } else {
        std::cout << "SK" << std::endl;
    }

    return 0;
}

/* solution 2 : solve with Dynamic Programming */
int Sol2() {
    int N = 0; /* the number of stone */
    std::array<int, MAX> arr = {0, 1, 2, };

    std::cin >> N;

    for(int i = 3; i <= N; i++) {
        arr.at(i) = Min((arr.at(i-3) + 1), (arr.at(i-1) + 1));
    }

    if(arr.at(N) % 2 == 0) {
        std::cout << "CY" << std::endl;
    } else {
        std::cout << "SK" << std::endl;
    }

    return 0;
}

int main() {
    Sol1();
    Sol2();
    return 0;
}