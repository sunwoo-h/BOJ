#include <bits/stdc++.h>
using namespace std;

const int n = 6; // 정점이 5개라서 6으로 선언
vector<int> adj[n];
int visited[n];

// DFS (깊이 우선 탐색)
void DFS(int u){
    visited[u] = 1;
    cout << u << '\n';
    for(int v : adj[u]){
        if(visited[v] == 0){
            DFS(v);
        }
    }
}

// BFS (너비 우선 탐색)
void BFS(int start){
    queue<int> q;
    memset(visited, 0, sizeof(visited)); // DFS에서 쓴 visited 초기화

    visited[start] = 1;
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << '\n';

        for(int v : adj[u]){
            if(visited[v] == 0){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);

    cout << "DFS 결과\n";
    DFS(1);

    cout << "BFS 결과\n";
    BFS(1);

    return 0;
}