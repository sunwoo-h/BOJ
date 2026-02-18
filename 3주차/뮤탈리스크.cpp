#include <bits/stdc++.h>
using namespace std;

int n, a[3], visited[64][64][64];

int combi[6][3] ={ // 경우의수 6 방향
	{9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3},
};

struct A{ // 구조체 정의 (3개의 값)
  int a, b, c; 
}; 
queue<A>q; 


int solve(int a, int b, int c){
  visited[a][b][c] = 1; // 방문처리
  q.push({a,b,c});
  while(q.size()){
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();
    if(visited[0][0][0]) break; // 0,0,0 을 방문했다면 멈춤
    for(int i = 0; i < 6; i++){ // 6방향 탐색
      int na = max(0, a - combi[i][0]); // 연산값이 음수가 되지 않도록 max처리
      int nb = max(0, b - combi[i][0]);
      int nc = max(0, c - combi[i][0]);
      if(visited[na][nb][nc]) continue; // 방문했으면 생략
      visited[na][nb][nc] = visited[a][b][c] + 1;  
      q.push({na, nb, nc}); 
    }
  }
  return visited[0][0][0] -1;
}



int main(){
  // 입력 받기
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  cout << solve(a[0], a[1], a[2]) << "\n";

  return 0;
}