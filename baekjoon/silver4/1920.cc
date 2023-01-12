#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N = 0; /* the number of compare element */
    int M = 0; /* the number of input element */
    
    std::cin >> N;
    std::vector<int> vec; /* store compare element */
    int temp = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        vec.push_back(temp);
    }

    std::sort(vec.begin(), vec.end());

    std::cin >> M;
    int input = 0;
    for(int i = 0; i < M; i++) {
        scanf("%d", &input);
        printf("%d\n", std::binary_search(vec.begin(), vec.end(), input));
    }

    return 0;
}
