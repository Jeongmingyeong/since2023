#include <iostream>
#include <vector>
#include <algorithm>
#define N_MAX 26
using namespace std;

// 지도의 크기 N 선언
int N = 0;

// 단지에 속하는 집의 수 저장 변수 및 배열
int cnt = 0;
vector<int> number_of_house;

// 지도 배열 선언
int map [N_MAX][N_MAX] = {0, };

// 지도의 (i, j) 위치를 방문했는지 확인하는 배열
bool is_visited[N_MAX][N_MAX] = {false, };

// dx, dy technique 에 사용할 변수 선언
int dx[4] = {0, 0, -1, 1}; // 상, 하, 좌, 우
int dy[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우

// 이동할 위치가 이동할 수 있는 유효한 위치인지 확인
bool InRange(int a, int b) {
    // 지도 안에 존재하는 위치인지 확인
    bool in_map = 0 <= a && a < N_MAX && 0 <= b && b < N_MAX;

    // 이동하고자 하는 위치에 집이 있는지
    bool exist_house = (map[a][b] == 1);

    // 지도안에 존재하는 위치이고, 집이 있는지에 대한 boolean 값 return
    return (in_map && exist_house);
}

// 지도를 하나씩 방문하며 연결된 가구를 하나의 단지로 구분
void Seperate(int a, int b) {
    // 이 함수를 실행했다면 집을 하나 방문한 것이므로 count 1 증가
    cnt++;

    // 움직이고자 하는 좌표 구하기 (상, 하, 좌, 우 모든 방향에 대해서)
    for(int i = 0; i < 4; i++) {
        int ni = a + dx[i];
        int nj = b + dy[i];   

        // 이동할 수 있는 위치인지와 그 위치를 방문여부 확인
        if(InRange(ni, nj) && (!is_visited[ni][nj])) {
            
            // 이동할 수 있는 위치고 아직 방문한 적 없는 위치라면 그 위치에 대해 다시 탐색
            is_visited[ni][nj] = true;
            Seperate(ni, nj);
        }     
    }
}

// 각 단지에 속하는 집의 수 출력하는 함수
void print_house () {
    for(int i = 0; i < number_of_house.size(); i++) {
        cout << number_of_house[i] << '\n';
    }
}

int main() {
    // 지도의 크기 입력
    cin >> N;

    // 지도에 작성되어있는 N 개의 자료 입력
    for(int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    // 단지의 개수를 세는 변수
    int result = 0;

    // 지도를 하나씩 방문하면서 단지를 구분
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            
            // 아직 방문하지 않았고, 집이 있는 위치에 대해서만 방문 
            if((!is_visited[i][j]) && (map[i][j] == 1)) {
                cnt = 0;
                is_visited[i][j] = true;
                Seperate(i, j);
                result ++; // 단지 개수 증가
                number_of_house.push_back(cnt); // 단지 내에 있는 집의 개수 저장
            }

            // 나머지 경우에 대해서는 방문했지만 집이 없으므로 탐색을 하지 않은 것이므로 true 저장
            is_visited[i][j] = true;

        }
    }

    // 각 단지에 속해있는 집의 수를 오름차순으로 정렬
    sort(number_of_house.begin(), number_of_house.end());

    // 단지의 수와 각 단지에 속해있는 집의 수 출력
    cout << result << '\n';
    print_house();
    
    return 0;

}
