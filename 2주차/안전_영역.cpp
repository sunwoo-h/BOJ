#include <bits/stdc++.h>
using namespace std;

int n, cnt, ret = 1; // ret = 1은 비가 0일때 결과 -> !! 문제 조건(최대 최소 경계) 잘 생각하기!

int area[104][104], visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<int> v; // 결과 담아둘 벡터

void dfs(int y, int x, int h){
  visited[y][x] = 1;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
    if(!visited[ny][nx] && area[ny][nx] > h){ // 안 들어간 곳이고, 높이가 h보다 크면
      dfs(ny,nx,h);
    }
  }
}


int main(){
  // 1. n 입력받기
  cin >> n;

  // 2. 지역정보 입력받기
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> area[i][j];
    }
  }


  for(int h = 1; h <= 100; h++){ // 물 높이 1~100 순회하며 반복

    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0); // visited 배열 초기화
    cnt = 0; // cnt 초기화

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(area[i][j] > h && !visited[i][j]){ // 물높이 보다 높고, 방문하지 않은 곳이면
          dfs(i,j,h);
          cnt++;
        }
      }
    }
    ret = max(ret,cnt); // rer과 cnt 비교해서 !최댓값 갱신! -> 최댓값 갱신 로직 자주 나오니까 기억
  }
  
  cout << ret << '\n';

  return 0;
}