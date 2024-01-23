#include <iostream>
using namespace std;

int calc_rate(long long x, long long y) {
  return (100 * y) / x;
}

int main() {

  // Declare three variables
  // 0 < x <= 1,000,000,000 
  //   => the range of "y" exceed the range of "int"
  // So, these variables are declared as the range of "long long"
  long long x, y, z;
  int count = -1;

  // input x and y
  // x is total plays
  // y is win games
  cin >> x >> y;

  // calculate z 
  z = calc_rate(x, y);

  // if z >= 99%, then print "-1"
  if (z >= 99) {
    cout << count << endl;
    return 0;
  }

  // if z <= 99, find result with binary search
  int left = 0;
  int right = 1000000000;
  int mid = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    long long newz = calc_rate(x+mid, y+mid);

    // if z < newz, then reduce the number of rounds
    if (z < newz) {
      right = mid - 1;
    }

    // else, increase the number of rounds
    else {
      left = mid + 1;
    }
  }

  // print result
  cout << left << endl;

  return 0;
}

