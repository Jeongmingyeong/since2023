// A -> B -> C -> D -> E 를 만족하는 경우가 있는지 확인하는 문제
#include <iostream>
#include <vector>
#define N_MAX 2001
#define M_MAX 2001 // 관계의 최대 개수
using namespace std;

// 관계를 저장할 graph 선언 (인접리스트 형식)
vector<int> graph[M_MAX];

// 방문 여부 저장 배열
bool is_visit[N_MAX] = {false, };

// A -> B -> C -> D -> E 만족하는지 확인하는 변수
bool is_possible = false;

// args : node = 현재 node, cnt = DFS 가 불린 횟수 (깊이)
void DFS(int node, int cnt) {
    // DFS 가 5번 불렸다면 즉, 5명이 A -> B -> C -> D -> E 처럼 연결이 되어있다면 즉시 탐색 종료
    if(cnt == 4) {
        is_possible = true;
        return;
    }
    // 방문여부 update
    is_visit[node] = true;

    // 현재 node 에 연결되어있는 모든 node 에 대해서 방문여부 확인 후 false 라면 DFS 로 방문
    for(int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];
        if(is_visit[next_node] == false) {
            DFS(next_node, cnt+1);

            // 현재 node 즉, code 상의 next_node 에 대해 DFS 로 방문한 뒤 다시 돌아왔다면
            // 다른 node 에 대해서 DFS 방문할 때 또 방문할 수 있어야 하므로 방문여부를 false 로 바꿔줌.
            // 즉, 이 문제는 back tracking 과 그래프탐색이 결합된 문제임.
            is_visit[next_node] = false;
        }
    }
}

int main() {
    // 사람의 수 N, 관계의 수 M 선언 및 입력
    int N = 0, M = 0;
    cin >> N >> M;

    // M 개의 관계 입력
    for(int i = 0; i < M; i++) {
        int a = 0, b = 0;
        cin >> a >> b;

        // a 와 b 가 친구라는 소리이니 graph 형태로 표현하면 양방향 그래프로 표현됨.
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // graph 를 DFS 탐색하는데 A -> B -> C -> D -> E 를 만족한다는 것은 DFS 를 최소 5번 중첩된다는 의미
    // 즉 0번 ~ N-1번까지의 사람들을 DFS 로 방문
    for(int i = 0; i < N; i++) {
        // 한번도 관계를 본 적 없는 즉, 방문하지 않았던 사람이라면 DFS 방문
        if(is_visit[i] == false) {
            DFS(i, 0);
            is_visit[i] = false;
        }

        // DFS 로 탐색했을 때 A -> B -> C -> D -> E 가 만족한다면 1 출력 후 종료
        if(is_possible) {
            cout << 1 << "\n";
            return 0;
        }
    }

    // A -> B -> C -> D -> E 를 만족하지 못했다면 반복문을 끝낸후 이 부분을 실행
    // 즉, 0 출력 후 프로그램 종료
    cout << 0 << "\n";
    return 0; 
}
