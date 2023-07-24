#include <iostream>
#define N_MAX 10
using namespace std;

int arr[N_MAX] = {0, };

int main() {
    /* the number of people */
    int N = 0; 
    cin >> N;

    /* input info about standing */
    for(int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;

        int index = 0; /* temp 가 저장될 위치 (index) */
        int count = 0; /* 앞에 나보다 키가 더 큰 사람이 설 자리 수 */
        int idx = 0; /* 배열을 돌 때 값을 비교하는 index */

        /* temp(나) 앞에 더 큰 사람이 서고 난 후 나의 위치 구하기 */
        while(count != temp) {
            if(arr[idx] == 0) {
                index++;
                count++;
                idx++;
            } else {
                index++;
                idx++;
            }
        }

        while(arr[index] != 0){ // 이미 이 위치에 어떠한 값이 저장되어있으면 다른 위치에 저장
            index++;
        }
        arr[index] = i+1;
    }

    /* print result */
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    printf("\n");
    return 0;
}
