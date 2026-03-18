#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, visited[1004], cnt;
vector<int> adj[1004];

void dfs(int i){
  visited[i] = 1;
  for(int k : adj[i]){
    if(!visited[k]) {
      dfs(k);
    }
  }
  return;
}

int main(){
  cin >> t;
  while(t--){

    // 인접리스트, 방문배열 초기화(매 반복마다 해줘야 함)
    for(int i = 0; i < 1004; i++) adj[i].clear(); 
    fill(visited, visited + 1004, 0);

    cnt = 0;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
      cin >> a >> b;
       // 양방향 간선 저장
      adj[b].push_back(a); 
      adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
      if(!visited[i]){
        dfs(i);
        cnt++;
      }
    }

    // 트리 조건
    // 1. E = V - 1
    // 2. dfs가 한방에 끝난 경우
    if(m == n - 1 && cnt == 1) cout << "tree" << "\n"; 
    else {
      cout << "graph" << '\n';
    }
  }

}