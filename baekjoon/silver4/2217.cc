#include <iostream>
#include <algorithm>

int main() {
    int N = 0; /* the number of rope */
    std::cin >> N;

    int rope[N]; /* store rope weight */

    for(int i = 0; i < N; i++) {
        std::cin >> rope[i];
    }

    std::sort(rope, rope+N, std::greater<>());

    for(int i = 0; i < N; i++) {
        rope[i] = rope[i] * (i+1);
    }

    std::sort(rope, rope+N, std::greater<>());

    std::cout << rope[0] << std::endl;
    return 0;
}
