#include <iostream>
#include <array>

int main() {
    int N = 0; /* length of table */
    int K = 0; /* distance of choose berger */
    int result = 0;

    std::cin >> N >> K;

    char arr[N];

    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        if(arr[i] != 'P') {
            continue;
        }

        for(int j = i-K; j <= i+K; j++) {
            if(arr[j] == 'H' && j >= 0 && j < N) {
                arr[j] = '-';
                result++;
                break;
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}