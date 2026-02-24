#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, h, a, b, ret = INF, visited[34][34];

bool check(){ // 출발 i -> 도칙 i 하는지 확인하는 함수
  for(int i = 1; i <= n; i++){
    int start = i; // start 지정
    for(int j = 1; j <= h; j++){ 
      if(visited[j][start]) start++; // 오른쪽으로 이동
      else if(visited[j][start - 1]) start--; // 왼쪽으로 이동
    }
    if(start != i) return false; // 출발 i와 도착i 가 다른 경우 false 리턴
  }
  return true;
}


void go(int here, int cnt){
  if(cnt > 3 || cnt >= ret) return; // 기저사례
  if(check()){ // 출발 i -> 도칙 i 만족하면 하면
    ret = min(ret,cnt); return;
  }
  for(int i = here; i <= h; i++){
    for(int j = 1; j < n; j++){
      if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue; // 사다리가 연속이면 지나감
      visited[i][j] = 1; // 방문처리
      go(i,cnt+1); // cnt 하나 올려서 재귀
      visited[i][j] = 0; // 원복
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  // 입력받기
  cin >> n >> m >> h;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    visited[a][b] = 1;
  }

  go(1,0); // 1부터 출발
  
  cout << ((ret == INF) ? -1 : ret) << "\n";



  return 0;
}