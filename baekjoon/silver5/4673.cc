#include <iostream>
#define MAX 10001

int func(int num) {
    int number = num;

    while(num != 0) {
        number = number + (num % 10);
        num = num / 10;
    }

    return number;   
}

int main() {
    int n = 0;
    bool check[MAX] = {false, };

    for(int i = 1; i < MAX; i++) {
        n = func(i);
        
        if(n < 10001) {
            check[n] = true;
        }
    }

    for(int i = 1; i < MAX; i++) {
        if(check[i] == false) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
