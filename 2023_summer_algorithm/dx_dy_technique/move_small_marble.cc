#include <iostream>
#define N_MAX 50
using namespace std;

// n: size of grid, t: time for move
int n, t = 0;

// create grid
// 구슬이 있는 위치의 값 : 1
int arr[N_MAX][N_MAX] = {0, };

// 범위 확인
bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// dx, dy technique (상, 우, 좌, 하)
int di[4] = {-1, 0, 0, 1}; 
int dj[4] = {0, 1, -1, 0};

// 바라보고 있는 방향을 숫자로 변환
int change_char2num(char dir) {
    int result = 0;
    switch (dir){
        case 'U':
            result = 0;
            break;
        case 'R':
            result = 1;
            break;
        case 'L':
            result = 2;
            break;
        case 'D':
            result = 3;
            break;
    }

    return result;
}

// 구슬의 위치 저장 변수
int row_m = 0;
int col_m = 0;

// 구슬이 있는 위치 확인
void find_marble() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 1){
                row_m = i;
                col_m = j;
                break;
            }
        }
    }
}

// 결과 출력
void print_result() {

    // 최종 구슬의 위치 확인
    find_marble();

    // print result
    cout << row_m+1 << " " << col_m+1 << endl;
}

int main() {
    // 여기에 코드를 작성해주세요.

    // input n, t
    cin >> n >> t;

    int row, col = 0; // position of marble
    char dir = ' ';    // 바라보고 있는 방향

    cin >> row >> col >> dir;

    // 구슬이 현재 있는 위치 표시
    arr[row-1][col-1] = 1;

    // 바라보고 있는 방향을 숫자로 변환
    int dir_num = change_char2num(dir);

    // t번 반복
    for(int i = 0; i < t; i++) {
        // 구슬이 있는 위치 확인
        find_marble();

        int ni = row_m + di[dir_num];
        int nj = col_m + dj[dir_num];

        if(in_range(ni, nj)) { // 이동했을 때 정상범위라면
            arr[row_m][col_m] = 0;
            arr[ni][nj] = 1;
        } else { // 이동했을 때 grid 를 벗어났다면
            // 바라보고있는 방향을 변경
            dir_num = 3 - dir_num;
        }
    }

    print_result();
    return 0;
}