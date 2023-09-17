#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 입력받는 밭의 크기 (N, M)
int N = 0, M = 0;

// 수확하는 옥수수 위치
int s_i = 0, s_j = 0;

// 밭 밖에서 볼수있는 최대가치의 옥수수
vector<int> outer;

// 밭의 정보 저장 배열
int arr[1000][1000] = {0, };

// 내림차순 정렬하기 위한 compare
bool compare(int a, int b) {
    return a > b;
}

// 범위확인 함수
bool InRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

// 상하좌우 탐색하고자 하는 방향
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// 수확할 옥수수 탐색 (현재 위치 x, y 를 입력받음.) - 안에서 탐색
int check_oksusu_inner(int x, int y) {

    int max = 0;

    // 상, 하, 좌, 우 4가지 방향에 대해 탐색
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 방문 가능한 위치인지 확인
        if(InRange(nx, ny)) {
            if(arr[nx][ny] > max) {
                max = arr[nx][ny];
                s_i = nx;
                s_j = ny;
            }
        }
    }

    return max;
}

// 밖에서 볼 수 있는 옥수수의 위치 구하기.
int check_oksusu_outer() {

    // 수확하는 옥수수의 위치
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == outer[0]) {
                s_i = i;
                s_j = j;
                break;
            }
        }
    }

    return outer[0];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 밭의 크기 입력
    cin >> N >> M;

    // 밭의 정보 입력
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // 수확할 옥수수의 수 입력 (K)
    int K = 0;
    cin >> K;

    // K 개의 옥수수 수확

    // 첫번째 옥수수는 가장 겉에 있는 옥수수 중 제일 가치가 높은 옥수수 수확 
    // 가장 겉에 있는 옥수수 전부 모으기
    for(int i = 0; i < N; i++) {
        outer.push_back(arr[i][0]);
        outer.push_back(arr[i][M-1]);
    }

    for(int i = 1; i < M-1; i++) {
        outer.push_back(arr[0][i]);
        outer.push_back(arr[N-1][i]);
    }

    // outer 정렬 (내림차순)
    sort(outer.begin(), outer.end(), compare);

    // 가장 처음 수확하는 옥수수
    int start = check_oksusu_outer();

    // 가장 처음 수확하는 옥수수의 위치 출력
    cout << s_i+1 << " " << s_j+1 << "\n";
    arr[s_i][s_j] = 0;

    // 수확했으니 원소 제거
    outer.erase(outer.begin());

    // 나머지 K-1 개의 옥수수에 대해서도 수확
    for(int i = 1; i < K; i++) {
        int a = s_i, b = s_j;

        int outer_value = check_oksusu_outer();
        int s_ii = s_i, s_ij = s_j;

        int inner_value = check_oksusu_inner(a, b);

        // cout << "inner: " << inner_value << " " << "outer: " << outer_value << endl;

        // outer 가 더 크다면 다시 s_i s_j 바꾸기
        if(inner_value <= outer_value) {
            s_i = s_ii;
            s_j = s_ij;
            // 수확했으니 원소 제거
            outer.erase(outer.begin());
        } 

        // 수확하는 옥수수의 위치 출력
        cout << s_i+1 << " " << s_j+1 << "\n";

        // 수확했다면 그 위치는 0으로 변경
        arr[s_i][s_j] = 0;
    }

    return 0;
}
