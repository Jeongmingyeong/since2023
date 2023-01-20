#include <iostream>

int main() {
    int T = 0; /* the number of test case */

    std::cin >> T;

    for(int i = 0; i < T; i++) {
        long long result = 1; /* store result */
        int N = 0; /* the number of left site */
        int M = 0; /* the number of right site */

        std::cin >> N >> M;

        int r = 1;
        for(int j = M; j > M-N; j--) {
            result = result * j;
            result = result / r;
            r++;
        }

        std::cout << result << std::endl;
    }
    return 0;
}
