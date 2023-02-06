#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int N = 0;
    cin >> N;

    deque<pair<int,int>> de;

    for(int i = 1; i <= N; i++) {
        int input = 0;
        cin >> input;
        de.push_back({i, input});
    }

    while(!de.empty()) {
        auto cur = de.front();
        cout << cur.first << " ";
        int element = cur.second;
        de.pop_front();

        if(element > 0) {
            element--;
            while(element != 0) {
                de.push_back(de.front());
                de.pop_front();
                element--;
            }
        } else {
            while(element != 0) {
                de.push_front(de.back());
                de.pop_back();
                element++;
            }
        }
    }
    cout << endl;
    return 0;
}
