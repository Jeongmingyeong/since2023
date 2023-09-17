#include <iostream>
using namespace std;

// 강의실 예약 확인 배열
bool check[200001][1000000001] = {false, };

// 강의실 예약 가능한지 확인 (true return 시 예약 가능함.)
bool check_reserv(int room, int start, int end) {
    bool result = true;

    for(int i = start; i < end; i++) {
        if(check[room][i]) {
            result = false;
            return result;
        }
    }

    return true;
}

// 강의실 예약 : 강의실번호, 시작시간과 종료시간을 입력받아 그 사이에 있는 시간대 전부 예약
void reservation(int room, int start, int end) {
    for(int i = start; i < end; i++) {
        check[room][i] = true;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 강의실 개수 N, 예약개수 M 입력.
    int N = 0, M = 0;
    cin >> N >> M;

    // M 개의 예약 입력
    for(int i = 0; i < M; i++) {
        // 강의실번호 num, 시작시간 start, 종료시간 end 순으로 입력
        int num = 0, start = 0, end = 0;
        cin >> num >> start >> end;

        // 예약 가능한지 확인
        if(check_reserv(num, start, end) == true) {
            // 예약 가능하다면 예약 후 "YES" 출력
            reservation(num, start, end);
            cout << "YES" << "\n";
        } else {
            // 예약 불가능하다면 "NO" 출력
            cout << "NO" << "\n";
        }
    }

    return 0;
}
