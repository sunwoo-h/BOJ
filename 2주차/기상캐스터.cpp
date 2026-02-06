#include <bits/stdc++.h>
using namespace std;

int H, W;
int dy = 0;
int dx = 1;
string s;

int a[104][104];
int visited[104][104];


void dfs(int y, int x){
  visited[y][x] = 1; // 방문 처리
  
  int ny = y + dy;
  int nx = x + dx;

  if(ny < 0 || nx < 0 || ny >= H || nx >= W) return; // 오버 플로우 체크
  if(!visited[ny][nx] && a[ny][nx] != 0) { // 방문한 곳이 아니고, 0이 아니면(=첫 시작점이 아니면)
    a[ny][nx] = a[y][x] + 1; // 1 더해주고
    dfs(ny,nx); // 다시 dfs 돌림
  }
}


int main() {

  // 1. 입력 받기
  cin >> H >> W;

  for(int i = 0; i < H; i++){
    cin >> s;
    for(int j = 0; j < W; j++){
      if(s[j] == 'c'){
        a[i][j] = 0;
      }
      else {
        a[i][j] = -1;
      }
    }
  }

 // 2. 동쪽으로만 DFS 돌림
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(a[i][j] == 0) { // 0이면 출발
        dfs(i,j);
      }
    }
  }


  // 3. 결과 출력
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;

}