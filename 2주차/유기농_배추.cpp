#include <bits/stdc++.h>
using namespace std;

int  t, ret, a, b;
int arr[54][54], visited[54][54];
int m, n, k;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

queue<pair<int,int>> q;


int main(){
  // 테스트 케이스 수 입력받기
  cin >> t;

  while(t--){ // 고급 스러운 반복 표현 ㅋㅋ
    // 재사용 값 초기화
    ret = 0; 
    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));


    // fill 함수 방법
    // fill(&arr[0][0], &arr[0][0] + 54 * 54, 0);
    // fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);


    // m, n, k 입력받기 -> 순서 주의! m부터 입력받음
    cin >> m >> n >> k;

    // 배추 입력받기
    for(int j = 0; j < k; j++){
      int x, y;
      cin >> x >> y;
      arr[y][x] = 1;
    }

    // 메인 로직
    // 맵을 전부 돌면서 BFS 돌리기
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(arr[i][j] == 1 && visited[i][j] != 1){
          ret++;
          visited[i][j] = 1;
          q.push({i,j});
          while(q.size()){
            tie(b, a) = q.front();
            q.pop();
            for(int k = 0; k < 4; k++ ){
              int ny = b + dy[k];
              int nx = a + dx[k];

              if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
              if(arr[ny][nx] == 1 && !visited[ny][nx]){
                visited[ny][nx] = 1;
                q.push({ny,nx});
              }
            }
          }
          
        }
      }
    }

    cout << ret << '\n';

  }


  return 0;
}