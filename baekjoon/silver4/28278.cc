#include <iostream>
#include <stack>

int main() {
    /* the number of order */
    int N = 0;
    scanf("%d", &N);
    std::stack<int> st;

    for (int i = 0; i < N; i++) {
        int first = 0;
        scanf("%d", &first);

        if (first == 1) {
            int second = 0;
            scanf("%d", &second);
            st.push(second);
        } else if(first == 2) {
            if(st.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", st.top());
                st.pop();
            }
        } else if(first == 3) {
            printf("%d\n", st.size());
        } else if (first == 4) {
            printf("%d\n", st.empty() ? 1 : 0);
        } else {
            printf("%d\n", st.empty() ? -1 : st.top());
        }
    }

    return 0;
}