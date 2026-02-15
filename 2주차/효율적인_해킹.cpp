#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx;
vector<int> adj[10001];
int visited[10001], arr[10001];


int dfs(int u){
  visited[u] = 1;
  int ret = 1; // 자기 자신 노드 카운팅
  
  for(int v :adj[u]){
    if(visited[v]) continue;
    ret += dfs(v);
  }

  return ret;
}

int main(){
  cin >> n >> m;

  // 인접 행렬 만들기
  while(m--){ // while 문좀 써라 ㅋㅋ
    cin >> a >> b;
    adj[b].push_back(a); // 노드 번호 그대로 입력받기
  }

  for(int i = 1; i <= n; i++){ // !! 노드 1번부터 dfs 돌리기(1부터 시작!) !!
    memset(visited, 0, sizeof(visited)); // 매번 초기화 시켜줘야 함 -> 그래야 순회 함!
    arr[i] = dfs(i); // dfs 돌리고 배열에 저장
    mx = max(arr[i], mx); // 최댓값 저장
  }

  for(int i = 1; i <= n; i++){
    if(mx == arr[i]){
      cout << i << " ";
    }
  }


  return 0;
}