#include <iostream>
#include <cstring>


// global variables
int count = 0; // count == change count
int length = 0; // length == string length


// get number from string
int get_number(std::string a) {
  int result = 0;

  for(int i = 0; i < length; i++) {
    result += (a[i] - '0');  
  }

  return result;
}


// print count and ("Yes" or "No")
void print_result(int num) {
  // print count
  std::cout << count << std::endl;
  
  // print "Yes" or "No"
  if (num % 3 == 0) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}


// main entry
int main() {
  std::string input = "";
  std::cin >> input;
  length = input.size();

  while(length > 1) {
    count ++;
    int sum = 0;

    sum = get_number(input);
    input = std::to_string(sum);
    length = input.size();
  }

  print_result(stoi(input));  

  return 0;
}

