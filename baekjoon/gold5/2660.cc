#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N_MAX 51 // 회원의 최대수는 50
using namespace std;

// 회원 사이의 친구관계를 저장할 graph 선언
vector<int> graph[N_MAX];

// score(i, j) := i 의 점수 j
vector< pair<int, int> > score;

// 방문 여부 확인 배열 
bool is_visit[N_MAX] = {false, };

// is_visit 배열 초기화
void init() {
    for(int i = 0; i < N_MAX; i++) {
        is_visit[i] = false;
    }
}

// BFS 로 계산한 점수를 정렬할 때 사용할 compare 함수
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    // pair 에서 두번째 원소가 score 이므로 second 를 기준으로 비교

    // 두번째 원소가 같으면 첫번째 원소 (회원번호) 를 오름차순으로 정렬
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

// 넓이우선탐색으로 각 회원의 점수 계산
void BFS(int i) {
    // BFS 탐색에서 사용할 queue 선언 (인자로는 <next node, level> 이 주어짐.)
    queue< pair<int, int> > q;

    // 몇 단계를 거쳐야 모든 사람의 친구인지 즉, i 의 점수 계산
    int total_level = 0; 

    // i 방문 여부 update 후 queue 에 push
    is_visit[i] = true;
    q.push(make_pair(i, 0));

    // queue 가 빌 때까지 탐색 반복
    while(!q.empty()) {
        int current = q.front().first;
        int level = q.front().second;
        total_level = max(total_level, level);
        q.pop();

        // current 에 연결되어있는 사람들에 대해 탐색 (queue 에 push) 
        for(int j = 0; j < graph[current].size(); j++) {
            int next = graph[current][j];
            // 다음 방문할 위치가 아직 방문하지 않았다면 queue 에 push
            if(is_visit[next] == false) {
                is_visit[next] = true;
                q.push(make_pair(next, level+1));
            }
        }
    }

    // 탐색을 끝냈으면, <회원번호, 점수> 를 pair 로 만들어 score vector 에 저장
    score.push_back(make_pair(i, total_level));
    return;
}

// 점수 계산 후 회장 후보의 수를 구하는 함수
int number_of_candi() {
    int min_score = score[0].second;
    // 회장 후보의 수 구할 변수
    int num_of_candi = 0;

    for(auto i : score) {
        int value = i.second;

        // min score 보다 큰 경우 바로 반복문 탈출 
        if(value > min_score) {
            break;
        }

        num_of_candi++;
    }

    return num_of_candi;
}

// 회장 후보 출력
void print_candi(int min_score) {
    for(auto i : score) {
        int person = i.first;
        int value = i.second;

        if(value > min_score) {
            return;
        }

        cout << person << " ";
    }
}

int main() {
    // 회원의 수 입력
    int N = 0;
    cin >> N;

    // -1 -1 을 입력받기 전까지 각 회원들의 친구관계 입력 (p1 p2 := p1 과 p2 가 친구임.)
    while(true) {
        int p1 = 0, p2 = 0;
        cin >> p1 >> p2;

        // 입력 종료조건 : 입력 마지막 줄에는 -1 을 두번 입력받음.
        if( (p1 == -1) && (p2 == -1)) {
            break;
        }

        // p1 과 p2 는 서로 친구이므로 양방향 간선으로 저장
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }

    // 모든 회원 각각 BFS 로 점수 계산
    for(int i = 1; i <= N; i++) {
        init(); // 방문여부 배열 초기화
        BFS(i); // i 회원의 점수 계산
    }

    // 점수 계산을 했다면 아래의 기준대로 정렬
    // 1. 점수가 낮은 순
    // 2. 점수가 같다면 회원번호 오름차순
    sort(score.begin(), score.end(), compare);

    // 회장 후보의 수 계산
    int num = number_of_candi();

    // 회장 후보의 점수 
    int min_score = score[0].second;

    // 첫째줄에 회장 후보의 점수와 후보의 수 출력
    cout << min_score << " " << num << "\n";

    // 둘째 줄에 회장 후보 번호 출력
    print_candi(min_score);
    cout << "\n";

    return 0;
}
