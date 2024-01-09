#include <iostream>
#include <string>

int main() {
  int n = 0;
  char digit = ' ';
  int count = 0; // frequency of digit

  // input n & digit
  std::cin >> n >> digit;

  // change int to string
  for(int i = 1; i <= n; i++) {
    std::string num = std::to_string(i);

    for(int j = 0; j < num.length(); j++) {
      if (num[j] == digit) {
        count ++;
      }
    }
  }

  // print result ( = count )
  std::cout << count << std::endl;

  return 0;
}

