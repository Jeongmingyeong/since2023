#include <iostream>
#include <queue>

#define N_MAX 100
#define M_MAX 100

using namespace std;

// 전역변수 설정
int N = 0, M = 0; // grid size (N x M)

// grid 선언
int graph[N_MAX][M_MAX] = {0, };

// 지나야 하는 최소의 칸 수 저장 배열
int result [N_MAX][M_MAX] = {0, };

// 상, 하, 좌, 우 를 탐색하기 위한 dx, dy 선언
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

// 방문 확인 배열
bool is_visit[N_MAX][M_MAX] = {false, };

// 가능한 범위인지 확인
bool inRange(int x, int y) {
    // grid 를 벗어나지는 않았는지 확인
    bool ingrid = (0 <= x && x < N && 0 <= y && y < M);

    // 그 위치에 갈수없는 즉, 값이 0인지 확인
    bool possible_pos = (graph[x][y] != 0);

    return (ingrid && possible_pos);
}

// BFS 에서 사용할 queue
queue< pair <int, int> > q;


// BFS 탐색
void BFS(int x, int y) {

    // queue 가 빌 때까지 반복
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        // 현재 (a, b) 위치에서 상, 하, 좌, 우 4가지 방향 확인
        for(int i = 0; i < 4; i++) {

            // 다음 위치의 좌표 구하기
            int nx = a + dx[i];
            int ny = b + dy[i];

            // 가능한 범위라면 방문 확인 후 방문하지 않았다면 queue 에 위치 저장 후 
            // 이동할 때 지나야 하는 칸을 이전 방문 위치 (a, b) 의 값에 1 추가해 현재 좌표에 저장
            if(inRange(nx, ny) && (is_visit[nx][ny] == false)) {
                q.push(make_pair(nx, ny));
                is_visit[nx][ny] = true;
                result[nx][ny] = result[a][b] + 1;
            }

        }
    }
}

int main() {
    // grid size 입력
    cin >> N >> M;

    // grid 입력 (공백없이 붙어서 입력으로 주어지므로 정수 하나씩 받아서 처리)
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    // 첫번째 위치 queue 에 저장 후 방문 표시
    q.push(make_pair(0, 0));
    is_visit[0][0] = true;

    // 시작위치도 칸을 세므로 시작위치의 결과값 1 저장
    result[0][0] = 1;

    // BFS 로 방문하며 지나야 하는 최소의 칸수 구하기
    BFS(0, 0);

    // 도착 위치의 방문 칸 수 출력 (result)
    cout << result[N-1][M-1] << endl;

    return 0;
}
