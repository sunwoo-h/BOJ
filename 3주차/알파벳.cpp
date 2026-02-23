#include <bits/stdc++.h>
using namespace std;

int r, c, ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[24][24];
int alpha[26];

void dfs(int y, int x, int len){
  ret = max(ret, len); // 최댓값 갱신

  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

    int idx = a[ny][nx] - 'A';
    if(alpha[idx]) continue;

    alpha[idx] = 1;            // 사용
    dfs(ny, nx, len + 1);      // 진행
    alpha[idx] = 0;            // 되돌리기(백트래킹)
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r >> c;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> a[i][j];
    }
  }

  alpha[a[0][0] - 'A'] = 1;
  dfs(0, 0, 1);

  cout << ret << "\n";
  return 0;
}