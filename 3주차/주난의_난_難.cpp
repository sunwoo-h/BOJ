#include <bits/stdc++.h>
using namespace std;
#define y1 suwoo

int n, m, x1, x2, y1, y2, cnt;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

char a[304][304];
int visited[304][304];
queue<pair<int,int>> q;

int main(){
  // 1. 입력받기
  cin >> n >> m;
  cin >> y1 >> x1 >> y2 >> x2;

  x1--; y1--; x2--; y2--;

  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < m; j++){
      a[i][j] = s[j];
    }
  }

  visited[y1][x1] = 1;
  q.push({y1,x1});

  while(a[y2][x2] != '0'){ // 범인이 0이 아닐 동안 반복(주난이가 범인 만나면 범인이 0으로 바뀌기 때문)
    cnt++;
    queue<pair<int,int>> temp; // 임시 큐

    while(q.size()){
      int y, x;
      tie(y, x) = q.front(); q.pop();

      for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
  
        if(ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx]) continue;
        
        visited[ny][nx] = cnt; // 방문한 곳을 다 cnt로 만들어버림

        if(a[ny][nx] != '0'){ // 0 이아니면
          // 벽/사람 → 부수고 다음 라운드
          a[ny][nx] = '0';
          temp.push({ny, nx}); // 임시로 큐에 저장!
        }
        else{
          // 빈칸 → 같은 라운드 확장
          q.push({ny, nx});
        }
      }
    }
    q = temp; // 다음 wave
  }

  printf("%d\n", visited[y2][x2]);
  return 0;
}
