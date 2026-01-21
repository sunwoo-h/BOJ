#include <bits/stdc++.h>
using namespace std;
const int n = 3;  // const로 상수 선언해줘야 아래 배열 선언 에러 안 남
int a[n][n], visited[n][n];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x){
  visited[y][x] = 1; // 방문하면 visitied 1로 바꿈
  cout << y << " : " << x << '\n';
  for(int i = 0; i < 4; i++){ // 4 방향 탐색
    int ny = y + dy[i];
    int nx = x + dx[i];
    
    // 아래의 3가지 상황이면, 아래의 go() 함수 실행 안 하고 다시 반복시작
    if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue; // 1. 맵의 범위를 추과할 때
    if(a[ny][nx] == 0) continue; // 2. 갈수 없는 곳일때(= 0일때)
    if(visited[ny][nx]) continue; // 3. 이미 갔던 곳일 때

    go(ny, nx); // 재귀 : 새로 계산된 (ny, nx)에서 다시 4 방향 탐색 시작
  }
  return;
}



int main() {
  // 맵 입력 받기
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  
  go(0,0); // (0,0)부터 탐색 시작
  
  // 입력
  // 1 0 1
  // 1 0 1
  // 0 1 1

  // 출력
  // 0 : 0    -> 0,0부터 출발
  // 1 : 0    -> [1,0] 이동하고 멈춤

  return 0;
}