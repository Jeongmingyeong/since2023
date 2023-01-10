#include <iostream>
#include <stack>
#include <string>
#include <array>
#include <string.h>

int main() {
    int N = 0; /* the number of testcase */
    std::stack<char> stack; /* store Parenthesis String */
    std::string result = ""; 
    
    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::string input;
        std::string result = "YES";

        std::cin >> input;

        /* stack clear */
        while(!stack.empty()) {
            stack.pop();
        }

        /* check "(" or ")" */
        for(int j = 0; j < input.length(); j++) {
            if(input[j] == '(') {
                stack.push(input[j]);
            } else if(input[j] == ')' && !stack.empty() && stack.top() == '(') {
                stack.pop();
            } else {
                result = "NO";
                break;
            }
        }

        /* if stack size == 0, this string is VPS */
        if(!stack.empty()) {
            result = "NO";
        }

        std::cout << result << std::endl;
    }
    return 0;
}
