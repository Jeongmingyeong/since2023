#include <iostream>

int main() {
    int N = 0; /* length of score list */
    int score = 0; /* new score */
    int P = 0; /* Maximum length of list */

    std::cin >> N >> score >> P;
    int list[100];

    for(int i = 0; i < N; i++) {
        std::cin >> list[i];
    }

    int count = 0;
    int rank = 1;
    for(int i = 0; i < N; i++) {
        if(list[i] > score) {
            rank++;
        } else if(list[i] == score) {
            rank = rank;
        } else {
            break;
        }
        count++;
    }

    if(count == P) {
        rank = -1;
    }
    if(N == 0) {
        rank = 1;
    }

    std::cout << rank << std::endl;
    return 0;
}
