#include <iostream>
#include <array>
#include <algorithm>
#define MAX 2250000

int main() {
    int N = 0; /* demention */
    int arr[MAX] = {0, };

    std::cin >> N;

    int size = N * N;
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + size);

    std::cout << arr[size-N] << std::endl;
    return 0;
}
