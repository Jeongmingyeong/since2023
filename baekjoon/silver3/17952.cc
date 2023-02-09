#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N = 0; /* minute */
    int result = 0;
    cin >> N;

    stack<int> sc; /* score */ 
    stack<int> rt; /* Remaining time */
    for(int i = 0; i < N; i++) {
        int homework = 0; /* 1 or 0 */
        cin >> homework;
        if(homework == 1) {
            int score, minute = 0;
            cin >> score >> minute;
            sc.push(score);
            rt.push(minute);
        } 
        if(!rt.empty()) {
            rt.top()--;
            if(rt.top() == 0) {
                result += sc.top();
                sc.pop();
                rt.pop();
            }
        } 
    }

    cout << result << '\n';
    return 0;
}
