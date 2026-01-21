#include <bits/stdc++.h>
using namespace std;

int n, m, ny, nx;
int y, x; // 승원이 위치
int z, w; // 당근마켓 위치
int y2, x2;

int dy[] ={-1, 0, 1, 0};
int dx[] ={0, 1, 0, -1};

int a[104][104];
int visited[104][104];

queue<pair<int, int>> q; //


void BFS(int y, int x){
  visited[y][x] = 1;
  q.push({y, x});

  while(q.size()){
    tie(y2, x2) = q.front(); // q의 젤 앞값을 u(here)로 지정
    q.pop(); // 지정했으면 버림

    for(int i = 0; i < 4; i++){ // 상하좌우 탐색
      int ny = y2 + dy[i]; // u(here) 에서 탐색
      int nx = x2 + dx[i]; // u(here) 에서 탐색
      if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue; // 오버플로우 방지
      if(a[ny][nx] == 1 && !visited[ny][nx]){ // 육지이고 방문하지 않았다면
        visited[ny][nx] = visited[y2][x2] + 1; // 최단 거리 배열 생성
        // visited[there] = visitied[here] + 1  ->  이 말과 동치!
        q.push({ny, nx});
      }
    }
  }
  cout << visited[z][w] << '\n';
}

int main() {
  // 입력 받기  
  cin >> n >> m;
  cin >> y >> x;
  cin >> z >> w;

  // 배열 입력 받기
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  } 

  BFS(y,x);

  return 0;
}