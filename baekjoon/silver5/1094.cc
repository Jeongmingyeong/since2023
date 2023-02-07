#include <iostream>
#include <string>
#include <bitset>
#define N 8
using namespace std;

int main() {
    int X = 0; /* length of stick */
    cin >> X;

    string binary = bitset<N>(X).to_string();

    int count = 0; /* the number of 1 */
    for(int i = 0; i < N; i++) {
        if(binary[i] == '1') {    
            count ++;
        }
    }

    cout << count << '\n';
    return 0;
}
