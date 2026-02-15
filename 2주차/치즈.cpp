#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, hour;
int a[104][104], visited[104][104];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

vector<pair<int,int>> v;

void dfs(int y, int x){
  visited[y][x] = 1;
  if(a[y][x] == 1){ // 치즈면
    v.push_back({y,x}); // 벡터에 좌표 넣고
    return; // 끝냄
  }
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny >= n || nx >= m || ny < 0 || nx < 0 ) continue;
    if(!visited[ny][nx]){
      dfs(ny,nx);
    }
  }
  return;
}



int main(){
  cin >> n >> m;

  // 좌표 입력 받기
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  while(true){
    // 초기화!! 중요
    fill(&visited[0][0], &visited[0][0] + 104*104, 0);
    v.clear();

    dfs(0,0); // 0,0 부터 dfs 돌림
    cnt = v.size(); // 가장자리 치즈들의 개수를 cnt에 저장
    for(pair<int,int> p : v){ // 치즈들 녹여 버려
      a[p.first][p.second] = 0;
    }

    // 다 녹았는지 확인하는 플래그 
    bool flag = 0;

    // 다 순회해봐서 
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(a[i][j] != 0) flag = 1; // 아직 치즈 남아있으면 flag = 1
      }
    }
    
    hour++; // 1시간 추가

    if(!flag) break; // 남은 치즈 없으면 반복문 탈출

  
  }

  cout << hour << '\n' << cnt << '\n';

  return 0;

}