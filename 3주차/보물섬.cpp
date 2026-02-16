#include  <bits/stdc++.h>
using namespace std;

int n, m, ret;
char a[54][54];
int visited[54][54];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

queue<pair<int,int>> q;

int main(){

  // 1. 지도 입력 받기  
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }


  // 2. BFS돌리기(최단경로까지)
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 'L'){ // '육지'일때만 BFS돌림
        fill(&visited[0][0], &visited[0][0] + 54*54, 0); // 시작지점이 다수이므로 초기화 해줘야 함
        queue<pair<int,int>> q; // 시작지점이 다수이므로 초기화 해줘야 함
      
        visited[i][j] = 1; // 방문처리
        q.push({i,j});
        while(q.size()){
          int x, y;
          tie(y, x) = q.front();
          q.pop();



          for(int k = 0; k < 4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];

            if(ny >= n || nx >= m || ny < 0 || nx < 0 ) continue; // 오버플로우 체크
            if(!visited[ny][nx] && a[ny][nx] == 'L'){ //방문하지 않았고, 육지이면
              visited[ny][nx] = visited[y][x] + 1; // 방문처리
              q.push({ny,nx});
              ret = max(ret, visited[y][x]); // 매 순회마다 결과값 저
            }
          }
        }
      }
    }
  }

  cout << ret ;

  

  return 0;
}