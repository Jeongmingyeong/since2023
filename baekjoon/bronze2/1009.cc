#include <iostream>

int main() {
    int T = 0; /* the number of test case */

    std::cin >> T;

    for(int i = 0; i < T; i++) {
        int a, b, result = 1;
        std::cin >> a >> b;
        
        /* focus on units */
        for(int i = 0; i < b; i++) {
            result = (result * a) % 10;
        }

        /* if 10th data (10 modulo == 0), he use 10th computer */
        if(result == 0) {
            result = 10;
        }

        std::cout << result << std::endl;
    }

    return 0;
}
