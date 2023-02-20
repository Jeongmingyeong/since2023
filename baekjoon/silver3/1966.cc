#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

int main() {
    int testcase = 0;
    std::cin >> testcase;

    for(int i = 0; i < testcase; i++) {
        int N = 0; /* the number of documents */
        int place = 0; /* when document was printed */
        std::vector<std::pair<int, int>> v;
        std::pair<int, int> comp;

        std::cin >> N >> place;

        for(int j = 0; j < N; j++) {
            int input = 0; /* importance of a document */
            std::cin >> input;
            if(j == place) {
                comp = std::make_pair(input, j);
            }
            v.push_back((std::make_pair(input, j)));
        }

        std::sort(v.begin(), v.end(), compare);

        int count = 1;
        for(int j = 0; j < v.size(); j++) {
            if(v.at(j) == comp) {
                printf("%d\n", count);
                break;
            } else {
                count++;
            }
        }
    }

    return 0;
}