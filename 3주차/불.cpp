#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int r, c, cnt, x, y, ret;
char a[1004][1004];
int fire_check[1004][1004], person_check[1004][1004];
pair<int,int> jihoon;
queue<pair<int,int>> q;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){

  // 1. 입력 받기
  cin >> r >> c;
  fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> a[i][j];
      if(a[i][j] == 'F'){ // 불인 경우
        fire_check[i][j] = 1; // 불났다고 표시
        q.push({i,j}); // 큐에 좌표 저장
      }
      else if(a[i][j] == 'J'){ // 지후니 좌표 저장
        jihoon = {i,j};
      }
    }
  }


  // 2. 불길 BFS 돌리기(여러개 가능)
  while(q.size()){
    tie(y,x) = q.front();
    q.pop();
    for(int i =0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny >= r || nx >= c || ny < 0 || nx < 0) continue;
      if(fire_check[ny][nx] != INF || a[ny][nx] == '#') continue; // 초기값이 아니고, 벽인 경우 패스
      fire_check[ny][nx] = fire_check[y][x] + 1; // 불길 +1
      q.push({ny,nx});
    }
  }

  // 3. 지훈이 BFS 돌리기
  person_check[jihoon.first][jihoon.second] = 1; // 지훈이 방문체크
  q.push({jihoon.first,jihoon.second});// 불과 동일한 큐에 넣기
  while(q.size()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    if(x == c - 1 || y == r - 1 || x == 0 || y == 0){
      ret = person_check[y][x];
      break;
    }
    for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= r || nx >= c || ny < 0 || nx < 0) continue;
			if(person_check[ny][nx] || a[ny][nx]=='#') continue; 
			if(fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
    }

  }

  if(ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE\n";
	return 0;

  return 0;
}