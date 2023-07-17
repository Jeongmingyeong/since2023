#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool is_visited[1001] = {false, };

void dfs(int n) {
    is_visited[n] = true;
    cout << n << " ";

    for(int i = 0; i < graph[n].size(); i++) {
        int a = graph[n][i];
        if(!is_visited[a]) {
            dfs(a);
        }
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    is_visited[n] = true;

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        cout << a << " ";

        for(int i = 0; i < graph[a].size(); i++) {
            int b = graph[a][i];
            if(!is_visited[b]) {
                q.push(b);
                is_visited[b] = true;
            }
        }
    }
}

int main() {
    
    // N is the number of vertax
    // M is the number of edge
    // V is start vertax
    int N, M, V = 0;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int v1, v2 = 0; // edge v1 -> v2
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i = 0; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    printf("\n");
    
    for(int i = 0; i < 1001; i++) {
        is_visited[i] = false;
    }

    bfs(V);
    printf("\n");
    return 0;
}