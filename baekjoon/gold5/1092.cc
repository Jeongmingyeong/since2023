#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> crane;
    std::vector<int> box;

    /* N : the number of crane */
    /* M : the number of box */
    int N, M = 0; 

    std::cin >> N;
    for(int i = 0; i < N; i++) {
        int temp = 0;
        std::cin >> temp;
        crane.push_back(temp);
    }

    std::cin >> M;
    for(int i = 0; i < M; i++) {
        int temp = 0;
        std::cin >> temp;
        box.push_back(temp);
    }

    sort(crane.begin(), crane.end(), std::greater<int>());
    sort(box.begin(), box.end(), std::greater<int>());

    if(crane[0] < box[0]) {
        printf("-1\n");
        return 0;
    }

    int result = 0;
    while(!box.empty()) {
        result += 1;
        for(int i = 0; i < crane.size(); i++) {
            for(int j = 0; j < box.size(); j++) {
                if(crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
