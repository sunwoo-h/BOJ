#include <bits/stdc++.h>
using namespace std;

const int n = 6; // 정점이 5개라서 6으로 선언해줌
vector<int> adj[n];
int visited[n];

void DFS(int u){
  visited[u] = 1;
  cout << u << '\n';
  for(int v : adj[u]){ // u에 인접한 요소들 탐색
    if(visited[v] == 0){
      DFS(v);
    }
  }
  cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
  return;
}

int main() {
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(4);
  adj[4].push_back(2);
  adj[2].push_back(5);
  DFS(1);
  return 0;
}