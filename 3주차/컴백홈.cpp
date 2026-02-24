#include <bits/stdc++.h>
using namespace std;

int r, c, k;
char a[10][10];
int visited[10][10];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int go(int y, int x){
  if(y == 0 && x == c - 1){ // 기저사례: 집 도착
    if(k == visited[y][x]) return 1; // K값과 최단경로 똑같으면 1리턴(결과에 +1 위함)
    return 0; // 아니면 0리턴(궁금하지 않은 값)
  }
  int ret = 0;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'T')continue;
		visited[ny][nx] = visited[y][x] + 1; // 경로 길이 구하기
		ret += go(ny, nx); // 결과값 갱신
		visited[ny][nx] = 0; // 원복
  }
  return ret;
}

int main() {
  cin >> r >> c >> k;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> a[i][j];
    }
  }

  visited[r-1][0] = 1;// 초기 방문 처리
  cout << go(r-1,0) << '\n';


  return 0;
}