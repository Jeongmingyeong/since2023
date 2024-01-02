#include <iostream>
#include <string>

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

// case1
bool check_include_vowel(std::string s) {
  for(int i = 0; i < s.size(); i++) {
    for(int j = 0; j < 5; j++) {
      bool found = s[i] == vowels[j];
      if (found) {
        return true;
      }
    }
  }

  return false;
}

// case2
bool check_conti_three_letters(std::string s) {
  int v_count = 0; // the number of consecutive vowels
  int c_count = 0; // the number of consecutive consonants

  for(int i = 0; i < s.size(); i++) {
    bool exist = false;
    for(int j = 0; j < 5; j++) {
      exist = (s[i] == vowels[j]);
      if(exist) {
        v_count += 1;
        c_count = 0;
        break;
      } 
    }

    // not exist vowel
    if(!exist) {
      v_count = 0;
      c_count += 1;
    }

    // terminate condition
    if(v_count >= 3 || c_count >= 3) {
      return false;
    }
  }

  return true;
}

// case3
bool check_conti_two_letters(std::string s) {
  int count = 1;
  char prev_letter = s[0];

  for(int i = 1; i < s.size(); i++) {

    // terminate condition
    if(prev_letter == s[i] && prev_letter != 'e' && prev_letter != 'o') {
      return false;
    }

    prev_letter = s[i];
    count = 1;
  }

  return true;
}

void print_result(bool total_condition, std::string s) {
  if (total_condition) {
    std::cout << "<" << s << "> is acceptable." << std::endl;
  } else {
    std::cout << "<" << s << "> is not acceptable." << std::endl;
  }
}

int main() {
  std::string input = "";

  while(true) {
    std::cin >> input;
    
    if(input.compare("end") == 0) {
      break;
    }

    bool case1 = check_include_vowel(input);  
    bool case2 = check_conti_three_letters(input);  
    bool case3 = check_conti_two_letters(input);

    bool total_cond = case1 && case2 && case3;
    print_result(total_cond, input);
  }

  return 0;
}

