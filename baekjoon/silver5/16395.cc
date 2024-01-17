#include <iostream>
using namespace std;

// global variables
int arr[31][31] = {0, }; // pascal triangle

// make pascal triangle ( C(n, k) = C(n-1, k-1) + C(n-1, k) )
void mk_pascal() {
  // step1. col = 1 : fill with 1
  for(int i = 0; i < 31; i++) {
    arr[i][0] = 1;
  }

  // step2 . fill the values up to the current position
  for(int i = 1; i < 31; i++) {
    for(int j = 1; j <= i; j++) {
      arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
    }
  }
}

// print arr (To check)
void print_arr() {
  for(int i = 0; i < 31; i++) {
    for(int j = 0; j < 31; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}


// entry program
int main() {

  // input n, k
  int n = 0; // number of rows
  int k = 0; // number of cols
  cin >> n >> k;

  // create pascal triangle
  mk_pascal();

  // print pascal
  // print_arr();

  // print result
  cout << arr[n-1][k-1] << endl;

  return 0;
}

