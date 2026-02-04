#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int sx, sy, ex, ey;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int a[104][104];

vector<int> v;

int dfs(int y, int x){
  a[y][x] = 1;
  int area = 1;         // 현재 칸 넓이 포함

  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
    if(a[ny][nx] != 1){
      area += dfs(ny, nx);
    }
  }

  return area;
}

int main() {

  cin >> m >> n >> k;


  // 좌표 입력받아서 1로 채우기
  for(int i = 0; i < k; i++){
    cin >> sx >> sy >> ex >> ey;

    for(int q = sx; q < ex; q++){
      for(int w = sy; w < ey; w++){
        a[w][q] = 1;
      }
    }
  }

  // dfs 순회
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(a[i][j] != 1){ // 1이 아닌곳만 순회
        int ret = dfs(i,j);
        v.push_back(ret);
      }
    }
  }


  // 오름차순 정렬
  sort(v.begin(),v.end());

  // 개수출력
  cout << v.size() << '\n'; 

  // 요소 출력
  for(int i : v){
    cout << i << " ";
  }


  return 0;
}