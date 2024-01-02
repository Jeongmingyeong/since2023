#include <iostream>
#include <algorithm>

int pig[6] = {0, };
int prev_pig[6] = {0, };

int calc_use_feed(int day) {
  int result = 0;
  
  if(day != 1) {
    for(int i = 0; i < 6; i++) {
      int left = (i + 6 - 1) % 6;
      int right = (i + 6 + 1) % 6;
      int opposite = (i + 3) % 6;

      pig[i] = prev_pig[i] + prev_pig[left] + prev_pig[right] + prev_pig[opposite];
    }

    std::copy(pig, pig+6, prev_pig);
  }

  for(int i = 0; i < 6; i++) {
    result += pig[i];
  }

  return result;
}

int main() {
  int T = 0; // the number of testcase
  std::cin >> T;

  for(int i = 0; i < T; i++) {
    int day = 1;
    int N = 0; // amount of feed
    std::cin >> N;
    for(int j = 0; j < 6; j++) {
      std::cin >> pig[j];
      prev_pig[j] = pig[j];
    }
    
    while(true) {
      int use_feed = calc_use_feed(day);
      
      // terminate condition : use_feed > N
      if(use_feed > N) {
        std::cout << day << std::endl;
        break;
      }

      // not terminated
      day++;
    }
  }

  return 0;
}

