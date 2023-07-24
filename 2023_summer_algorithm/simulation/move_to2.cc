// 숫자가 가장 큰 인접한 곳으로 동시에 이동 문제

// step 1. 구슬을 어디로 이동할 지 결정 및 이동
// step 2. 겹치는 구슬 확인 및 삭제

#include <iostream>
#define N_MAX 20
using namespace std;

/* n: grid size, m: the number of marble, t: time */
int n, m, t = 0;

/* create grid */
int arr[N_MAX][N_MAX] = {0, };

/* create grid for marble position */
int marble[N_MAX][N_MAX] = {0, };

// 범위 확인
bool InRange(int row, int col) {
    return (0 <= row && row < n && 0 <= col && col < n);
}

/* 주변 인접한 4개 중 가장 큰 위치 반환 함수 */
int find_max(int pos_row, int pos_col) {
    int di[4] = {-1, 1, 0, 0}; // up, down, left, right
    int dj[4] = {0, 0, -1, 1}; // up, down, left, right
    int max_value, max_i, max_j = 0;

    for(int i = 0; i < 4; i++) {
        int ni = pos_row + di[i];
        int nj = pos_col + dj[i];

        // index 가 범위 안의 값이라면 계산
        if (!InRange(ni, nj)){
            if(max_value < arr[ni][nj]) {
                max_i = ni;
                max_j = nj;
            }
        }

        // index 가 범위 밖의 값이라면 다음 위치 계산
    }

    return max_i, max_j;
}

/* 구슬을 이동시키는 함수 */
void moveAll() {
    /* 구슬이 이동한 결과를 저장할 temp 배열 */
    int temp[N_MAX][N_MAX] = {0, };
    // temp[i][j] : 그 위치에 있는 구슬의 개수

    /* 구슬이 있는 곳 확인해서 이동 */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(marble[i][j] == 0) { /* 구슬이 존재하지 않은 위치임. */
                continue;
            }

            /* 구슬이 이동할 위치 find */
            int row, col = find_max(i, j);

            /* 기존에 구슬이 있던 자리 0으로 만들고, 새로운 위치로 이동 */
            marble[i][j] = 0;
            marble[row][col]++;
        }
    }
}

/* 겹치는 구슬 제거 함수 */
void remove() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            /* 같은 위치에 구슬이 두개 이상이라면, 구슬 제거*/
            if(marble[i][j] >= 2) {
                marble[i][j] = 0;
            }
        }
    }
}

/* 구슬의 개수 count */
int count_marble() {
    int num = 0; /* 구슬의 개수 */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            num += marble[i][j];
        }
    }

    return num;
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    /* input value */
    cin >> n >> m >> t;

    /* input info grid */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    /* input position of marble */
    for(int i = 0; i < m; i++) {
        int r, c = 0;
        cin >> r >> c;
        r = r - 1;
        c = c - 1;
        marble[r][c] = 1; /* 1 이면 현재 구슬이 있는 위치 */
    }

    /* t번 반복 */
    for(int i = 0; i < t; i++) {
        // step 1. 구슬을 어디로 이동할 지 결정 및 이동
        moveAll();

        // step 2. 겹치는 구슬 확인 및 삭제
        remove();
    }

    /* 구슬의 개수 count */
    int result = count_marble();

    /* print result */
    cout << result << endl;

    return 0;
}