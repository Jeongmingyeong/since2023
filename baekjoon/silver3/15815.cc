#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<int> st;
    std::string input = "";

    std::getline(std::cin, input);

    for(int i = 0; i < input.length(); i++) {
        char temp = input[i];

        /* if character is number */
        if(temp >= '0' && temp <= '9') {
            st.push(temp - '0');
        } else { /* if character is an arithmetic symbol */
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if(temp == '+') {
                st.push(b + a);            
            } else if(temp == '-') {
                st.push(b - a);
            } else if(temp == '*') {
                st.push(b * a);
            } else if(temp == '/') {
                st.push(b / a);    
            }
        }
    }

    std::cout << st.top() << std::endl;
    return 0;
}
