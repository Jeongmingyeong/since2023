#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct STUDENT {
    string name;
    int korean;
    int english;
    int math;
};

bool compare (STUDENT a, STUDENT b) {
    if(a.korean == b.korean && a.english == b.english && a.math == b.math) {
        return a.name < b.name;
    } else if (a.korean == b.korean && a.english == b.english) {
        return a.math > b.math;
    } else if(a.korean == b.korean) {
        return a.english < b.english;
    } else {
        return a.korean > b.korean;
    }
}

int main() {
    int N = 0; /* the number of student */
    cin >> N;

    vector<STUDENT> vec(N);
    
    for(int i = 0; i < N; i++) {
        cin >> vec[i].name >> vec[i].korean >> vec[i].english >> vec[i].math;
    }

    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i < N; i++) {
        cout << vec[i].name << '\n';
    }

    return 0;    
}
