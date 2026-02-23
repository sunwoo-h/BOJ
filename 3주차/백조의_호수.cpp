#include <bits/stdc++.h>
using namespace std;
const int max_n = 1501;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 

int visited_swan[max_n][max_n], visited[max_n][max_n];
int R, C, day;
int swanY, swanX, y, x;
char a[max_n][max_n];
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;

// 백조 만남 확인 함수(BFS)
bool move_swan(){
  while(swanQ.size()){
  tie(y, x) = swanQ.front(); 
      swanQ.pop();
      for(int i = 0; i < 4; i++){
          int ny = y + dy[i];
          int nx = x + dx[i];
          if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
          visited_swan[ny][nx] = 1; // 방문처리
          if(a[ny][nx] == '.')swanQ.push({ny, nx}); // 물이면 swanQ에 넣음
          else if(a[ny][nx] == 'X') swan_tempQ.push({ny, nx}); // X면 swan_tempQ에 넣음(임시큐)
          else if(a[ny][nx] == 'L') return true; // 백조 만나면 true 리턴
      }
  }
return false;
}

// 물 녹이기 함수(BFS)
void water_melting(){
  while(waterQ.size()){
    tie(y, x) = waterQ.front();  
    waterQ.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;
        if(a[ny][nx] == 'X'){
          visited[ny][nx] = 1; // 1. 방문처리
          water_tempQ.push({ny, nx}); // 2. water_tempQ에 넣기
          a[ny][nx] = '.'; // 3. .으로 만들어버리기
        }
    }
  }
}


// 큐 초기화 함수
void Qclear(queue<pair<int, int>> &q){
  queue<pair<int, int>> empty; // 새로 하나 지역으로 만들어두고
  swap(q,empty); // 스왑 갈김
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력받기
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L'){swanY = i; swanX = j;} // 백조 위치 저장
            if(a[i][j] == '.' || a[i][j] == 'L'){ // 이동가능한 좌표이면
              visited[i][j] = 1; // 1. 방문 처리하고
              waterQ.push({i, j}); // 2. waterQ에 넣음
            } 
        }
    }

    swanQ.push({swanY, swanX}); // 백조 위치 q에 저장(move_swan함수에서 사용!)
    visited_swan[swanY][swanX] = 1; // 백조 방문 처리

    while(true){
        if(move_swan()) break; // 백조 만나면 반복 멈춤(!!반복문 탈출사례 초기에 기입!!)

        water_melting(); // 물 녹이기

        // 위에 이제 temp에 저장해둔 거 다시 본래의 큐에 할당
        waterQ = water_tempQ;
        swanQ = swan_tempQ;

        // Temp 큐 지우기(전역 할당해줬으니 지워야 함)
        Qclear(water_tempQ);
        Qclear(swan_tempQ);

        day++;
    }
    cout << day << "\n";
    return 0;
}
