#include <iostream>
#include <string>
#include <cmath>

int main() {
    int N = 0; /* goal channel */
    std::cin >> N;

    int n = 0; /* the number of broken channel */
    std::cin >> n;

    char button[11] = {' ',}; /* broken channel button */
    for (int i = 0; i < n; i++) {
        std::cin >> button[i];
    }

    if (N == 100) {
        printf("%d\n", 0);
        return 0;
    }

    std::string num = "";
    bool pos_channel[1000002];
    for(int i = 0; i < 1000002; i++) {
        pos_channel[i] = true;
        num = std::to_string(i);
        for(int j = 0; j < n; j++) {
            if(num.find(button[j]) != std::string::npos) { /* exist button[j] in num */
                pos_channel[i] = false;
                break;
            }
        } 
    }

    pos_channel[100] = true; /* start channel is 100 */

    int small = 210000000;
    for(int i = N; i >= 0; i--) {
        if(pos_channel[i]) {
            small = i;
            break;
        }
    }

    int big = 210000000;
    for(int i = N; i <= 1000002; i++) {
        if(pos_channel[i]) {
            big = i;
            break;
        }
    }

    int a = abs(N - small) + std::to_string(small).length();
    int b = abs(N - big) + std::to_string(big).length();
    int c = abs(N - 100);

    int result_ = a < b ? a : b;
    int result =  result_ < c ? result_ : c;

    printf("%d\n", result);
    return 0;
}