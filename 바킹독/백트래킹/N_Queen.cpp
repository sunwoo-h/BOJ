#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool colUsed[20]; // (열)
bool diag1Used[40]; // row + col (대각선 /)
bool diag2Used[40]; // row - col + (n-1) (대각선 \)

void go(int row){ // 행을 인자로 받아서 반복
  if(row == n){
    cnt++;
    return;
  }

  for(int col = 0; col < n; col++){ // 열마다 반복
    if(colUsed[col]) continue;
    if(diag1Used[row + col]) continue;
    if(diag2Used[row - col + (n - 1)]) continue;// n-1인 이유는 음수 방지를 위함(0부터 시작하도록 평행이동 시킴)
    // row - col 은 0-3 = -3 처럼 음수가 나올 수 있음!
    // 왜? : row, col의 범위는 0 ~ n-1
    // 최솟값 : -(n-1)
    // 즉, 전부 n-1을 더해버리면 최솟값은 0부터 시작!


    // 퀸 배치
    colUsed[col] = true;
    diag1Used[row + col] = true;
    diag2Used[row - col + (n - 1)] = true;

    go(row + 1);

    // 원복
    colUsed[col] = false;
    diag1Used[row + col] = false;
    diag2Used[row - col + (n - 1)] = false;
  }
}

int main(){
  cin >> n;
  go(0);
  cout << cnt;
  return 0;
}