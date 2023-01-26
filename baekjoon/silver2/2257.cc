#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input = ""; /* input chemical formula */
    int answer = 0;

    std::cin >> input;

    std::stack<std::string> st; /* store char */
    for(int i = 0; i < input.length(); i++) {
        std::string s = "";
        s += input[i];
        if(s == "(" || s == "H" || s == "C" || s == "O") {
            st.push(s);
        } else if(s == ")") {
            int middle = 0; /* store intermediate calculation results */
            while(!st.empty() && st.top() != "(") {
                if(st.top() == "H") {
                    middle += 1;
                } else if(st.top() == "C") {
                    middle += 12;
                } else if(st.top() == "O") {
                    middle += 16;
                } else {
                    middle += std::stoi(st.top());
                }
                st.pop(); /* pop 'H', 'C', 'O' from stack */
            }
            st.pop(); /* pop '(' from stack */
            st.push(std::to_string(middle));

        } else if(s >= "2" && s <= "9") {
            int temp = 0; /* store intermediate calculation results */
            if(st.top() == "H") {
                temp += 1;
            } else if(st.top() == "C") {
                temp += 12;
            } else if(st.top() == "O") {
                temp += 16;
            } else {
                temp += std::stoi(st.top());
            }
            st.pop(); /* pop 'H', 'C', 'O' from stack */
            st.push(std::to_string(temp * std::stoi(s)));
        }
    }

    /* print result */
    while(!st.empty()) {
        if(st.top() == "H") {
            answer += 1;
        } else if(st.top() == "C") {
            answer += 12;
        } else if(st.top() == "O") {
            answer += 16;
        } else {
            answer += std::stoi(st.top());
        }
        st.pop();
    }

    std::cout << answer << std::endl;
    return 0;
}
