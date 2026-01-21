#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m, ret, ny, nx;
int a[104][104];
bool visited[104][104];



void DFS(int y, int x){
  visited[y][x] == 1; // 방문 넣고
  for(int i = 0; i < 4; i++){ // 상하좌우 돌리기
    ny = y + dy[i];
    nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue; // underflow overflow 방지
    if(a[ny][nx] == 1 && !visited[ny][nx]){ // 육지이고, 방문하지 않았다면
      DFS(ny, nx);
    }
  }
}




int main() {
  // 1. 입력 받기
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  // 2. a배열 순회하며 DFS 돌리기
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a[i][j] == 1 && !visited[i][j]){ // 요소가 1이고(육지이고) 방문하지 않았다면
        ret ++; // ret + 1 하고
        DFS(i,j); // 방귀 뀌기
      }
    }
  }

  return 0;
}