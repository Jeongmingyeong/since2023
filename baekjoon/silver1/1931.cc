#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    int N = 0; /* the number of room */
    std::vector<std::pair<int, int>> vec; /* start time & finish time */
    int result = 1;

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        int start = 0;
        int end = 0;

        std::cin >> start >> end;

        vec.push_back(std::make_pair(end, start));
    }

    std::sort(vec.begin(), vec.end()); /* sort by end time */

    int end_time = vec[0].first; /* 1st end time */
    for(int i = 1; i < N; i++) {
        if(end_time <= vec[i].second) {
            result++;
            end_time = vec[i].first;
        }
    }

    printf("%d\n", result);
    return 0;
}
