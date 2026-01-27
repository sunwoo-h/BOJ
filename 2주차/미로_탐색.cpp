#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, y, x;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[104][104], visited[104][104];

queue<pair<int,int>> q;


int main() {
  // 1. n,m 입력 받기
  cin >> n >> m;

  // 2. 맵 입력 받기
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%1d", &a[i][j]);
    }
  }

  // 3. BFS 돌리기
  visited[0][0] = 1; // 출발점 방문처리
  q.push({0,0}); // 시작점 큐에 푸시
  while(q.size()) { // 큐에 값이 있는 동안
    tie(y, x) = q.front(); // 젤 앞요소로 지정
    q.pop(); // 큐 뺴기
    for(int i = 0; i < 4; i++){ // 인접 요소 방문
      int ny = y + dy[i];
      int nx = x + dx[i];
      
      if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue; // 오버플로우 체크
      if(a[ny][nx] != 0 && visited[ny][nx] == 0){ // 길이 0이 아니고, 방문한 적이 없는 경우에
        visited[ny][nx] = visited[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }

  cout << visited[n - 1][m - 1] << '\n';

  return 0;
}