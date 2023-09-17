#include <iostream>
#include <algorithm>
using namespace std;
#define N_MAX 101

// 대여소에 위치한 자전거의 개수 (처음 배치된 개수)
int a[N_MAX] = {0, };

// 대여소에 위치한 자전거의 개수 (나중에 확인된 개수)
int b[N_MAX] = {0, };

int main() {

    // 타슈 대여소의 개수 입력
    int N = 0;
    cin >> N;

    // 각 대여소에 배치된 자전거 개수 입력
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 추후 확인된 자전거 개수 입력
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }

    // 횟수 계산
    int result = 0;

    // a[i] - b[i] 의 값중 양수인 값들만 모두 더하기 (sum(a) == sum(b) 가 보장되므로)
    for(int i = 0; i < N; i++) {
        if(a[i] - b[i] > 0) {
            result += (a[i] - b[i]);
        }
    } 

    // 횟수 출력
    cout << result << endl;
    return 0;
}
