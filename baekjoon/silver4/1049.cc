#include <iostream>

int main() {
    int N = 0; /* the number of broken line */
    int M = 0; /* the number of brand */
    int a = 0; /* set prize */
    int b = 0; /* single prize */
    int set = 1000; /* minimum of set prize */
    int single = 1000; /* minimum of single prize */

    std::cin >> N >> M;

    for(int i = 0; i < M; i++) {
        std::cin >> a >> b;
        set = std::min(set, a);
        single = std::min(single, b);
    }

    /*
     * 1. buy only set [ (N/6 + 1) * set ]
     * 2. buy only single [ N * single ]
     * 3. buy set and single [ (N/6 * set) + (N%6 * single) ]
     */
    int min_prize =
        std::min((N/6 + 1) * set, std::min((N * single), (N/6 * set) + (N%6 * single)));

    printf("%d\n", min_prize);
    return 0;
}
