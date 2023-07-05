#include <iostream>

int main() {
    int n = 0; /* the number of paper */
    std::cin >> n;
    int store[100][100] = {0, };

    for(int i = 0; i < n; i++) {
        int a, b = 0;
        std::cin >> a >> b;
        for(int j = a-1; j < a + 9; j++) {
            for(int k = b - 1; k < b + 9; k++) {
                store[j][k] = 1;
            }
        }
    }

    int sum = 0; /* store area */
    for(int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            sum += store[i][j];
        }
    }

    printf("%d\n", sum);
    return 0;
}