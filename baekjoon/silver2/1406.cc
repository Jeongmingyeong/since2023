#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input = ""; /* input string */
    int N = 0; /* the number of input command */
    std::string cmd; /* input command */
    char character; /* input character */

    std::cin >> input;
    std::cin >> N;

    std::stack<char> left_st; /* left stack Based on the cursor */
    std::stack<char> right_st; /* right stack Based on the cursor */

    for(int i = 0; i < input.length(); i++) {
        left_st.push(input[i]);
    }

    for(int i = 0; i < N; i++) {
        std::cin >> cmd;

        if(cmd.compare("L") == 0) {
            if(left_st.empty()) {
                continue;
            } 
            char temp = left_st.top();
            left_st.pop();
            right_st.push(temp);

        } else if(cmd.compare("D") == 0) {
            if(right_st.empty()) {
                continue;
            } 
            char temp = right_st.top();
            right_st.pop();
            left_st.push(temp);

        } else if(cmd.compare("B") == 0) {
            if(left_st.empty()) {
                continue;
            }
            left_st.pop();
            
        } else if(cmd.compare("P") == 0) {
            std::cin >> character;
            left_st.push(character);
        }
    }

    while(!left_st.empty()) {
        right_st.push(left_st.top());
        left_st.pop();
    }

    /* print result */
    while(!right_st.empty()) {
        std::cout << right_st.top();
        right_st.pop();
    }

    std::cout << std::endl;
    return 0;
}
