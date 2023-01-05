#include <iostream>
#include <array>
#define MAX 500

int Max (int A, int B) {
    return A > B ? A : B;
}

int main() {
    int size = 0; /* size of triangle */
    int triangle[MAX][MAX]; /* input triangle & memoization array */

    std::cin >> size;

    /* input triangle */
    for(int i = 0; i < size; i++) {
        for(int j = 0; j <= i; j++) { /* input size = i */
            std::cin >> triangle[i][j];
        }
    }

    /* memoization */
    int max = 0; /* store max value */
    for(int i = 0; i < size; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) { /* if the value is on the left */
                triangle[i][j] = triangle[i-1][0] + triangle[i][j];
            } else if (j == i) { /* if the value is on the right */
                triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
            } else { /* if the value is on the middle */
                triangle[i][j] =
                    Max((triangle[i-1][j-1] + triangle[i][j]), (triangle[i-1][j] + triangle[i][j]));
            }

            max = Max(max, triangle[i][j]);
        }
    }

    std::cout << max << std::endl;
    return 0;
}
