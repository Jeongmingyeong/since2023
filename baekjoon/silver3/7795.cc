#include <iostream>
#include <algorithm>

int main() {
    int T = 0; /* the number of testcase */
    int N = 0; /* size of A */
    int M = 0; /* size of B */

    std::cin >> T;

    for(int i = 0; i < T; i++) {
        std::cin >> N >> M;
        int A[N];
        int B[M];
        
        for(int j = 0; j < N; j++) {
            std::cin >> A[j];
        }
        
        for(int j = 0; j < M; j++) {
            std::cin >> B[j];
        }

        std::sort(A, A+N);
        std::sort(B, B+M);

        int result = 0;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(A[j] > B[k]) {
                    result++;
                } else {
                    break; /* go to line 28 */
                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
