#include <iostream>
#include <deque>
using namespace std;

// 전역변수 설정 (N : 컨베이어벨트 길이, K : 내구도가 0인 칸의 최대 개수)
int N = 0, K = 0;

// 컨베이어벨트 내구도 관리 공간
deque<int> hp;

// 컨베이어벨트위에 물건 존재여부 관리
deque<bool> conv;

// step1. 벨트 회전 (로봇과 함께)
// deque 를 사용하다 보니 deque 의 가장 마지막 원소를 가장 앞에 push 하면 회전이 됨.
void rotate() {
    // 내구도를 회전
    hp.push_front(hp.back());
    hp.pop_back();

    // 물건 존재여부역시 함께 회전
    conv.push_front(conv.back());
    conv.pop_back();

    // 내리는 위치인 N-1 위치는 언제나 로봇이 도착하면 바로 내리니 false 설정
    conv[N-1] = false;
}

// step2. 로봇 이동 (벨트가 움직이는 방향으로)
// N번째 위치에서는 무조건 로봇이 내려질테니 1번째 ~ N-1번째에 대해서만 로봇을 움직여주면 됨.
void move_robot() {
    for(int i = N-2; i >= 0; i--) {

        // 이동 조건 : 이동하려는 칸에 로봇 존재 x && 이동하려는 칸의 내구도 1 이상 && 현재 i 위치에 로봇이 있으면
        if((conv[i+1] == false) && (hp[i+1] > 0) && (conv[i] == true)) {
            conv[i+1] = true;
            conv[i] = false;
            hp[i+1] --;
        }

        // 이동할 수 없다면 현재 위치의 가만히 있으므로 변화 X
        // N번째 위치에 로봇이 도달했다면 바로 내려줘야하므로 N번째 위치의 conv 는 언제나 false
        conv[N-1] = false;

    }
}

// step3. 벨트 위에 로봇 올리기 (올리는 위치의 칸이 내구도가 0이 아니면)
void put_robot() {
    // 올리는 위치의 칸의 내구도가 0이 아니고 && 로봇이 없다면 로봇 올림 (내구도 1 감소)
    if((conv[0] == false) && (hp[0] > 0)) {
        conv[0] = true;
        hp[0] --;
    }

}

// step4. 내구도가 0인 칸의 개수 확인 (return : 내구도가 0인 칸의 개수)
int check() {
    int count = 0;
    for(int i = 0; i < 2*N; i++) {
        if(hp[i] == 0) {
            count ++;
        }
    }

    return count;
}

int main() {
    // 컨베이어벨트 길이 N 과 종료조건 K 입력
    cin >> N >> K;

    // A1 ~ A2n 까지 입력
    for(int i = 0; i < 2*N; i++) {
        int input = 0;
        cin >> input;

        // 컨베이어벨트 내구도 관리 queue 에 저장
        hp.push_back(input);

        // 아직 로봇이 없으니 컨베이어벨트 위치에 false 로 저장
        conv.push_back(false);
    }

    // 현재 몇단계 수행중인지 저장하는 변수 선언
    int step = 1;

    // 종료조건과 일치하기 전까지 step1 ~ 4 까지 반복수행한다.
    while(true) {
        // step 1 ~ 4 수행
        rotate();
        move_robot();
        put_robot();

        // 종료조건 : 내구도가 0인 칸의 개수가 K 개 이상
        int count = check();
        if(count >= K) {
            cout << step << endl;
            return 0;
        }

        // 종료조건에 걸리지 않으면 단계를 올리고 step 1 다시 진행
        step++;
    }

    return 0;
}