#include <bits/stdc++.h>
using namespace std;

int n, l, r,sum, cnt;
int a[54][54], visited[54][54];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<pair<int,int>> v;

void dfs(int y, int x){
  visited[y][x] = 1;
  v.push_back({y,x}); // 시작좌표 v에 저장
  sum += a[y][x]; // 시작 좌표 sum값에 저장 

  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny >= n || nx >= n || nx < 0 || ny < 0 || visited[ny][nx] ) continue; // 오버플로우 체크, 방문 이력 체크
    if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) { // 차이가 범위에 있으면
      v.push_back({ny,nx}); // 벡터에 저장해둠
      sum += a[ny][nx]; // 누적합 저장
      dfs(ny,nx); // dfs돌리기
    }
  }
  return;
}

int main() {
  // 1. 입력받기
  cin >> n >> l >> r;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }


  while(true){ // 무한루프
    bool flag = 0; // 인구이동이 일어났는지 조건 만족 확인 flag
    fill(&visited[0][0], &visited[0][0] + 54*54, 0); // 테스트 케이스 별로 초기화 필요

    // dfs 돌리기
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(!visited[i][j]){ // 방문한 곳이 아니면
          v.clear(); // 좌표 저장 벡터 초기화
          dfs(i,j);
          if(v.size() == 1 ) continue;
          for(pair<int,int> b : v){ //벡터 순회
            a[b.first][b.second] = sum / v.size();
            flag = 1; // 인구이동 일어남 표시
          }
        }
      }
    }
    if(!flag) break; // 인구이동이 안 일어났으면 반복문 탈출
    cnt++; //인구이동 회수 추가

  }

  cout << cnt;


  return 0;
  
}