#include <iostream>
#include <list>
#include <string>
using namespace std;

// list of password key
list<char> password;

// get correct password
void get_correct_key(string pwd) {
  list<char>::iterator cursor = password.begin();
  
  for(char c : pwd) {
    switch(c){
      // backspace
      case '-':
        // check cursor is at the beginning
        if(cursor != password.begin()) {
          cursor = password.erase(--cursor);
        }
        break;

      // left arrow
      case '<':
        // check cursor is at the beginning
        if(cursor != password.begin()) {
          cursor--;
        }
        break;

      // right arrow
      case '>':
        // check cursor is at the end
        if(cursor != password.end()) {
          cursor++;
        }
        break;

      // numbers and letters
      default:
        password.insert(cursor, c);
    }
  }
}

// print password (list -> string)
void print_password() {
  for(char key : password) {
    cout << key;
  }
  cout << endl;
}

int main() {
  // input # of testcase
  int testcase = 0;
  cin >> testcase;

  // store input password
  string input_pwd = "";

  // execute #testcase times
  for(int i = 0; i < testcase; i++) {
    // input password
    cin >> input_pwd;

    // initialize password list
    password.clear();

    // get password
    get_correct_key(input_pwd);
  
    // print result
    print_password();
  }
  
  return 0;
}

