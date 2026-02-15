#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[10][10], visited[10][10];
vector<pair<int,int>> virusList, wallList;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};


void dfs(int y , int x){
  visited[y][x] = 1; // 방문처리

  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny >= n || nx >= m || ny < 0 || nx < 0) continue; // 오버플로우 체크
    if(visited[ny][nx] || a[ny][nx] == 1 ) continue; // 방문한 곳이거나 벽인 경우
    visited[ny][nx] = 1; // 방문처리
    dfs(ny,nx);
  }
  return;
}


// 바이러스 퍼뜨리기
int solve() {
  fill(&visited[0][0], &visited[0][0] + 10*10, 0);// 방문 배열 초기화
  for(pair<int, int> b : virusList){ // 바이러스 리스트의 좌표 탐색
    dfs(b.first,b.second); // dfs 돌리기
  }

  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 0 && !visited[i][j]) cnt++; // 0이고 방문한 곳이 아니면
    }
  }

  return cnt;

}


int main(){
  //  n, m  입력
  cin >> n >> m;

  // 배열 a 입력
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
      if(a[i][j] == 2) virusList.push_back({i,j}); // 바이러스 좌표 저장 -> 나중에 dfs 돌리기 위함
      if(a[i][j] == 0) wallList.push_back({i,j}); // 벽이 될 수 있는 좌표 저장 -> 여기만 조합 돌리기 위함
    }
  }
  
  // 0인 부분 경우의 수 조합 돌리기 -> n*mC3
  for(int i = 0; i < wallList.size(); i++){
    for(int j = 0; j < i ; j++){
      for(int k = 0; k < j; k++){
        // 완탐
        a[wallList[i].first][wallList[i].second] = 1;
        a[wallList[j].first][wallList[j].second] = 1;
        a[wallList[k].first][wallList[k].second] = 1;
        ret = max(ret, solve()); // 이 상태에서 결과값 갱신

        //원복
        a[wallList[i].first][wallList[i].second] = 0;
        a[wallList[j].first][wallList[j].second] = 0;
        a[wallList[k].first][wallList[k].second] = 0;

      }
    }
  }

  cout << ret << '\n';
  return 0;
}

