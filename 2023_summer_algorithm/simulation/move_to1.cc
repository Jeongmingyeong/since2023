// 숫자가 더 큰 인접한 곳으로 이동 문제

#include <iostream>
#define N_MAX 100
using namespace std;

int grid [N_MAX][N_MAX] = {0, };

// n : size of grid 
// r : row of start position
// c : col of start position
int n, r, c = 0;

int drow[4] = {-1, 1, 0, 0}; // up, down, left, right
int dcol[4] = {0, 0, -1, 1}; // up, down, left, right

bool inRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

// arg : 현재 위치 row, col & max:현재 나의 값
// return : 현재 위치에서 인접한 위치의 값 return
int find_big (int max) {
    int temp_row, temp_col = 0;
    int result_max = 0;
    for(int i = 0; i < 4; i++) {
        temp_row = r + drow[i];
        temp_col = c + dcol[i];

        // 이동시킨 위치가 grid 의 범위를 벗어나면 continue
        if(!inRange(temp_row, temp_col)) {
            continue;
        }

        // 이동시킨 위치가 grid 의 범위 안이라면 현재의 내 값과 비교
        if(grid[temp_row][temp_col] > max) {
            // 크다면 max update 후 바로 반복문 탈출
            result_max = grid[temp_row][temp_col];
            break;
        }

        // 작다면 다음 위치 확인
    }

    // 현재 나의 값이 가장 크다면 0 return
    if(result_max == 0) {
        return 0;
    }

    // max 값을 찾았으면 출력 후 max 값 return
    printf("%d ", result_max);

    r = temp_row;
    c = temp_col;

    return result_max;
}

int main() {
    // 여기에 코드를 작성해주세요.

    // input size, row, col
    cin >> n >> r >> c;
    
    // 위치를 index 로 변환 
    r = r - 1; 
    c = c - 1;

    // input info grid
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int s_r = 0;
    int s_c = 0;
    int max = 0;

    cout << grid[r][c] << " ";
    
    do{
        s_r = r;
        s_c = c;
        max = find_big(grid[s_r][s_c]);
    } while(max != 0); 

    printf("\n");

    return 0;
}