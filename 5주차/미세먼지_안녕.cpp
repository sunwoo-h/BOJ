#include <bits/stdc++.h>
using namespace std;

int n, m, t, ret;
int a[54][54]; // 입력 배열
int temp[54][54]; // 임시 배열

vector<pair<int,int>> v1, v2;

// 위쪽 공기청정기 방향(오,위,왼,아)
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};

// 아래쪽 공기청정기 방향(오,아,왼,위)
int dy2[] = {0,1,0,-1};
int dx2[] = {1,0,-1,0};

void mise_go(int dy[], int dx[]){ 
  fill(&temp[0][0], &temp[0][0] + 54 * 54, 0); // 임시 배열 초기화
  queue<pair<int, int>> q; 

  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          if(a[i][j] != -1 && a[i][j]){ // 공청기가 아니고 값이 있으면
              q.push({i, j}); // 큐에 좌표 저장
          }
      }
  }

  while(q.size()){ // 큐 요소 다 없어질때까지
    int y, x;
    tie(y, x) = q.front(); q.pop(); 
    int spread = a[y][x] / 5; 
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i]; 

      if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == -1) continue; 
      temp[ny][nx] += spread;
      a[y][x] -= spread;
    }
  }

  // 원본 배열에 다시 저장
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          a[i][j] += temp[i][j];
      }
  }

  return;
}  


// 공청기 순환 경로 만들기
// 공청기 위치가 주어졌을때 바람이 이동하는 순환 경로 저장하는 함수
vector<pair<int, int>> chung(int sy, int sx, int dy[], int dx[]){   
  vector<pair<int, int>> v; // 경로를 벡터로 저장

  int cnt = 0; 
  int y = sy; 
  int x = sx;

  while(true){ 
      int ny = y + dy[cnt];
      int nx = x + dx[cnt];  
      if(ny == sy && nx == sx)break;
      if(ny < 0 || ny >= n || nx < 0 || nx >= m){ // 격자 밖으로 나가면
          cnt++; // 다음 방향으로 꺾음
          ny = y + dy[cnt];
          nx = x + dx[cnt];
      } 
      if(ny == sy && nx == sx)break; // 공청기 자신을 제외한 바람 경로 칸들을 순서대로 저장
      y = ny; x = nx; 
      v.push_back({ny, nx});
  }
  return v;
} 


// 공청기 가동
void go(vector<pair<int, int>> &v){  
  // 뒤에서 부터 한 칸씩 당기기
  for(int i = v.size() - 1; i > 0; i--){
      a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
  } 
  
  // 공기청정기 바로 옆칸(공청기에서 나오는 바람)은 0(깨끗한 공기))
  a[v[0].first][v[0].second] = 0; 
  return;
}

int main(){
  //  1. 입력 받기
  cin >> n >> m >> t;
  bool flag = 1; // 위아래 공청기 구분용 플래그
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m ; j++){
      cin >> a[i][j];
      if(a[i][j] == -1) {
        if(flag){
          v1 = chung(i, j, dy1, dx1);  // 위쪽 공청기 순환 경로
          flag = false;
        } else v2 = chung(i, j, dy2, dx2); // 아래쪽 공청기 순환 경로
      }
    }
  }

  // t초동안 스프레드
  while(t--){
    mise_go(dy1, dx1);
    go(v1); // 위쪽 공청기 가동
    go(v2); // 아래쪽 공청기 가동
  }


  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(a[i][j] != -1)ret += a[i][j];
    }
  }
  cout << ret << "\n";

  return 0;
}