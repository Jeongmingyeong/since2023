#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 10

int main() {
    int N = 0; /* the number of words */
    int alpha[26] = {0, }; /* count alphabet */
    int result = 0;
    std::string input[MAX]; /* store input string */
    int length[MAX]; /* length of input string */

    scanf("%d\n", &N);
    for(int i = 0; i < N; i++) {
        std::cin >> input[i];
        length[i] = input[i].length();
    }

    int cal = 0;
    for(int i = 0; i < N; i++) {
        cal = 1;
        for(int j = length[i]-1; j >= 0; j--) {
            alpha[input[i][j] - 'A'] += cal;
            cal *= 10;
        }
    }

    std::sort(alpha, alpha+26, std::greater<>());

    for(int i = 0; i < 10; i++) {
        result += alpha[i] * (9-i);
    }

    printf("%d\n", result);
    return 0;
}
