#include <iostream>
using namespace std;

// N is day, M is # of withdraw
int N, M;

// list of money to spend
int money[100001] = {0, };

// get minimum K with binary search
int get_min_money(int total) {
  int result = 0; // minimum K
  int left = 1;
  int right = total;
  int mid = 0; // withdraw money
  
  while(left <= right) {
    mid = (left + right) / 2;
    int current_money = mid;
    int cnt = 1; // # of withdraw
    bool pass = true; // today_money < withdraw money ?
    
    for(int i = 0; i < N; i++) {
      // if today_money > withdraw money? increase withdraw money
      if(money[i] > mid) {
        pass = false;
        break;
      }
      
      // if today_money > current_money? withdraw money
      if(money[i] > current_money) {
        current_money = mid;
        cnt++;
      }

      // spend money
      current_money -= money[i]; 
    }

    // handle withdraw money
    // case1. (today_money > withdraw money) or (# of withdraw > N)
    // increase withdraw money and search again
    if(!pass || cnt > M) {
      left = mid + 1;
    }

    // case2. not case1
    // decrease withdraw money and search again
    else {
      result = mid;
      right = mid - 1;
    }
  }

  return result;
}

int main() {
  
  // input N and M
  cin >> N >> M;
  
  int total_money = 0;
  // input money to spent
  for(int i = 0; i < N; i++) {
    cin >> money[i];
    total_money += money[i];
  }
  
  // get minimum # of K
  int K = get_min_money(total_money);

  // print result K
  cout << K << endl;

  return 0;
}

