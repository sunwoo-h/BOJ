#include <bits/stdc++.h>
using namespace std;
int ret = 1e9;

int n, a[14][14], visited[14][14];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};


int setFlower(int y, int x){
  visited[y][x] =1;
  int s = a[y][x];
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    visited[ny][nx] = 1;
    s += a[ny][nx];
  }
  return s;
}

bool check(int y, int x){
  if(visited[y][x]) return 0;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny<0 || ny>=n || nx < 0 || nx >= n || visited[ny][nx]) {
      return 0;
    } 
  } 
  return 1;
}


void eraseFlower(int y, int x) {
  visited[y][x] = 0;
  for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      visited[ny][nx] = 0;
  }
}

void flower(int cnt, int hap){
  if(cnt == 3){ // 기저사례(종료조건)
    ret = min(ret, hap);
    return;
  }

  // 배열 순회하면서
  for (int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(check(i,j)){ // 심을 수 있는 곳이면
        flower(cnt+1, hap + setFlower(i,j)); // 재귀
        eraseFlower(i,j); // 원복
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  // 입력받기
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  
  flower(0,0);
  cout << ret;

  return 0;
}