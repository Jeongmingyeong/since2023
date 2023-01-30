#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int N = 0; /* the number of parrots */

    cin >> N;

    string tmp;
    getline(cin, tmp); /* remove '\n' */

    vector<queue<string>> q(N+1); /* store parrots words */
    for(int i = 0; i < N + 1; i++) { /* input string include a sentence cseteram wrote down */
        string temp;
        getline(cin, temp);
        istringstream ss(temp);

        string s;
        while(getline(ss, s, ' ')) { /* parsing based on ' ' */
            q[i].push(s);
        }
    }

    bool ispossible = false;
    int q_size = q[N].size(); /* queue size is changing continuously */

    for(int i = 0; i < q_size; i++) {
        string word = q[N].front();
        for(int j = 0; j < N; j++) {
            if((!q[j].empty()) && ( q[j].front() == word)) {
                q[j].pop();
                q[N].pop();
                ispossible = true;
                break;
            }
        }

        if(ispossible == false) {
            cout << "Impossible" << endl;
            return 0;
        } else {
            ispossible = false;
        }
    }

    for(int i = 0; i < N; i++) {
        if(!q[i].empty()) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    
    cout << "Possible" << endl;
    return 0;
}
