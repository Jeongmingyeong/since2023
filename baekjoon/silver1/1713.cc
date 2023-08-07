#include <iostream>
#include <vector>
#include <algorithm>
#define NUM_MAX 101
using namespace std;

// step1. 비어있는 사진 틀 생성
// step2. 사진틀에 입력받은 추천학생이 존재하는지 확인
// step3. step2 가 true 라면 추천수만 up || false 라면 사진틀에 넣고 추천수 up
// step4. 추천받은 학생에 대해 전부 작업을 완료했다면 오름차순 정렬
// step5. 정렬되어있는 사진틀 출력

// 전역변수 선언 (N : 사진틀의 개수, k : 친구들 추천 총 횟수)
int N = 0, k = 0;

// 사진틀에 저장된 시간 기록 배열 (추천이 될 때의 시간 기록할 배열)
// 이 배열에 들어간 값이 작을수록 오래된 것임.
int t[NUM_MAX] = {0, };

// 추천수 기록 배열
int num[NUM_MAX] = {0, };

// step1. 비어있는 사진 틀 생성 (사진을 계속 교체해야하므로 vector 로 생성)
vector<int> frame;

// 정렬할 때 사용하는 compare 함수
bool comp(int a, int b) {
    // 정렬기준1. 추천수가 같을 때 오래된 친구 제거 -> 기간에 따라 오래된 친구가 뒤로 가도록 정렬
    if(num[a] == num[b]) {
        if(t[a] > t[b]) {
            return true;
        } 
    }

    // 정렬기준2. 내림차순 정렬 (추천수가 적은 친구를 사진틀에서 제거해야하는데 가장 뒤에 있는 것이 편함.)
    else if (num[a] > num[b]) {
        return true;
    } else {
        return false;
    }

    return false;
}

// 사진틀에 추천받은 학생이 존재하는지 여부 판별 함수
bool exist (int student_number) {
    // 사진틀을 돌면서 student 가 존재하는지 확인
    for(int i = 0; i < frame.size(); i++) {
        if(frame[i] == student_number) {
            return true;
        }
    }

    // 위 조건에 한번도 걸리지 않았다면 존재하지 않음.
    return false;
}

int main () {
    // 사진틀의 개수 (N), 추천 총 횟수 (k) 입력
    cin >> N >> k;

    // 추천받은 학생을 나타내는 번호 빈칸을 두고 입력
    for(int i = 0; i < k; i++) {
        int student = 0;
        cin >> student;

        // step2. 사진틀에 추천받은 학생 있는지 확인
        // 사진틀에 추천받은 학생이 있다면 추천수만 up
        if(exist(student)) {
            num[student]++; // 추천수 up
        }

        // 사진틀에 추천받은 학생이 없다면
        else {

            // step3. 사진틀에 추천받은 학생 게시 
            // 사진틀이 비어있을 땐 바로 게시
            if(frame.size() < N) {
                frame.push_back(student);
            } 

            // 사진틀이 꽉 차있다면 
            // 1. 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제
            // 2. 1번 조건 학생이 여러명인 경우 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제
            else {
                // 위의 2가지 경우에 만족하는 학생을 제거하기 위해 사진틀 정렬
                sort(frame.begin(), frame.end(), comp);

                // comp 함수에 의해 2가지 경우에 만족하는 학생이 가장 뒤에 위치
                int remove_student = frame.back();
                t[remove_student] = 0;
                num[remove_student] = 0;

                // 즉 frame 의 가장 마지막원소를 제거한 후 추천학생 추가하면 됨.
                frame.pop_back();
                frame.push_back(student);
            }

            t[student] = i; // 사진틀에 들어간 시기 저장
            num[student]++; // 추천수 저장
        }       
    }

    // 사진틀을 학생번호에 대한 오름차순 정렬
    sort(frame.begin(), frame.end());

    // 사진틀에 저장되어있는 학생 출력
    for(int i = 0; i < frame.size(); i++) {
        cout << frame[i] << " ";
    }

    printf("\n");
    return 0;
}
