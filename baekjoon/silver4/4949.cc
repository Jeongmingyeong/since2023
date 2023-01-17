#include <iostream>
#include <stack>
#include <string>

int main() {
    while(true) {
        std::string input = "";
        std::stack<char> st; /* store bracket */
        //std::stack<char> small; /* small bracket */
        std::getline(std::cin, input);
        bool result = true; /* store result */

        if(input.length() == 1 && input[0] == '.') {
            break;
        }

        for(int i = 0; i < input.length(); i++) {
            if(input[i] == '[' || input[i] == '(') {
                st.push(input[i]);
            } 
            
            if (input[i] == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    result = false;
                    break;
                }
            } else if(input[i] == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    result = false;
                    break;
                }
            }
        }

        if(st.empty() && result) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0; 
}
