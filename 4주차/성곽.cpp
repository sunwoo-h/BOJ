#include <bits/stdc++.h>
using namespace std;

int n, m, w = 1, ret; // w는 자기 자신 포함이라 초기값 1로 설정
const int dy[] = {0, -1, 0, 1}; // 0번째를 서쪽으로 설정
const int dx[] = {-1, 0, 1, 0};
int a[54][54], visited[54][54];
int roomNum[54][54];      // 각 칸이 몇 번 방인지 저장
int roomSize[2504];       // 각 방 번호의 넓이 저장 (최대 50*50)

void dfs(int y, int x, int num){
  visited[y][x] = 1;
  roomNum[y][x] = num; // 방번호 기록

  for(int i = 0; i < 4; i++){
    if(!(a[y][x] & (1 << i))){ // 비트가 안 켜져 있으면 이동가능!
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny >= n || nx >= m || ny < 0 || nx < 0 ) continue;// 오버플로우 체크
      if(visited[ny][nx]) continue;
      w++;
      dfs(ny,nx,num);
    }
  }
  return;
}

int main(){
  cin >> m >> n; // 거꾸로 입력받는 거 주의

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  int cnt = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!visited[i][j]){ // 방문하지 않은곳을 탐색해야
        w = 1;
        cnt++;
        dfs(i,j,cnt);
        roomSize[cnt] = w; // cnt번 방의 넓이 저장
        ret = max(ret, w);
      }
    }
  }

  // 1. 이 성에 있는 방의 개수
  cout << cnt << '\n';

  // 2. 가장 넓은 방의 넓이
  cout << ret << '\n';

  // 3.하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
  int ans = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int d = 0; d < 4; d++){
        int ny = i + dy[d];
        int nx = j + dx[d];

        if(ny >= n || nx >= m || ny < 0 || nx < 0) continue;

        // 현재 칸과 옆 칸이 서로 다른 방이면
        if(roomNum[i][j] != roomNum[ny][nx]){
          ans = max(ans, roomSize[roomNum[i][j]] + roomSize[roomNum[ny][nx]]); // 최댓값 갱신
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;

}