#include <iostream>
#include <vector>
#define N_MAX 101
using namespace std;

// 컴퓨터의 수 n, 컴퓨터가 연결된 edge 의 수 m 선언
int n = 0, m = 0;

// 네트워크를 저장하는 graph 선언
vector<int> graph[N_MAX];

// 방문했는지 여부 확인하는 bool 배열 선언
bool is_visit[N_MAX] = {false, };

// 웜 바이러스에 걸리게 되는 컴퓨터의 수 저장 변수 선언
int number_of_com = 0;

void Search(int node) {
    for(int i = 0; i < graph[node].size(); i++) {
        // 현재 연결되어있는 모든 node 를 탐색
        int current = graph[node][i];

        // 방문하지 않은 node 라면
        if(!is_visit[current]) {
            is_visit[current] = true;
            number_of_com ++;
            Search(current);
        }
    }
}

int main() {
    // 컴퓨터의 수, 컴퓨터가 연결된 edge 의 수 차례로 입력
    cin >> n >> m;

    // m 개의 edge 입력
    for(int i = 0; i < m; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 1 번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 구해야하므로 1번부터 탐색
    is_visit[1] = true;
    Search(1);

    // 결과 출력
    cout << number_of_com << endl;
    return 0;
}