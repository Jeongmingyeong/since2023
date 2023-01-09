#include <iostream>
#include <queue>
#include <array>
#define MAX 5000

int main() {
    int N = 0; /* the number of people */
    int K = 0; /* remove K-th person from queue */
    std::array<int, MAX> result; /* store result */

    std::cin >> N >> K;

    std::queue<int> q;

    for(int i = 1; i <= N; i++) {
        q.push(i);
    }

    int temp = 0;
    int index = 0; /* result array index */
    while(!q.empty()) {
        for(int i = 0; i < K-1; i++) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }

        temp = q.front();
        q.pop();
        result.at(index) = temp; 
        index++;
    }

    std::cout << "<";
    for(int i = 0; i < N-1; i++) {
        std::cout << result.at(i) << ", ";
    }

    std::cout << result.at(N-1) << ">" << std::endl;
    return 0;
}
