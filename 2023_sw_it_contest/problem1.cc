#include <iostream>
using namespace std;

int main() {
    int A = 0, B = 0;

    cin >> A >> B;

    int result = 0;

    // 패티의 개수가 치즈의 개수보다 최소 1개 이상 많지 않은 경우
    if (A <= B) {
        result = A + A - 1;
    } 
    
    // 치즈의 개수보다 1개 더 많은 패티를 고를 수 있는 경우
    else {
        result = B + B + 1;
    }

    cout << result << endl;
    return 0;
}
