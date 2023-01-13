#include <iostream>

int main() {
    long long S = 0; /* sum of number */
    int N = 0; /* Maximum number */

    std::cin >> S;

    while(S > 0) {
        N++;
        S = S - N;
    }

    if(S < 0) {
        N--;
    } 

    printf("%d\n", N);
    return 0;
}
