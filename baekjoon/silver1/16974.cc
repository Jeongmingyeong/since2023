#include <iostream>
#include <string>

long long burger[51];
long long patty[51];

void Make_burger(int N) {
    burger[0] = 1; /* length of burger */
    patty[0] = 1; /* the number of patty */

    for(int i = 1; i <= N; i++) {
        burger[i] = 1 + burger[i-1] + 1 + burger[i-1] + 1;
        patty[i] = patty[i-1] + 1 + patty[i-1];
    }
}

long long ate_patty(int n, long long x) { /* n is level */
    if (n == 0) { /* base case */
        return x;
    } 
    
    if(x == 1) { /* base case*/
       return 0; /* ate nothing */
    } else if (x <= (1 + burger[n-1])) {
        return ate_patty(n-1, x-1);
    } else if (x == (1 + burger[n-1] + 1)) {
        return patty[n-1]+1;
    } else if (x <= (1 + burger[n-1] + 1 + burger[n-1])) {
        return patty[n-1] + 1 + ate_patty( n-1, x-(1+burger[n-1]+1) );
    } else {
        return patty[n-1] + 1 + patty[n-1];
    }
}

int main () {
    int N = 0; /* level-N */
    long long X = 0; /* the number of patty and bread */

    scanf("%d %lld", &N, &X);
    Make_burger(N);
    printf("%lld\n", ate_patty(N, X));
    return 0;
}