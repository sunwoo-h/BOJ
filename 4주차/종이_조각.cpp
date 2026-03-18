#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[4][4];


int main(){
  cin >> n >> m;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%1d", &a[i][j]);
    }
  }

  for(int s = 0; s < (1 << (n*m)); s++){ // n*m 사각형을 0과 1로 만드는 경우의 수
    int sum = 0;
    
    // 1. 가로 : 0인 부분 계산
    for(int i = 0; i < n; i++){ // 행 탐색
      int cur = 0;
      for(int j = 0; j < m; j++){
        int k = i * m + j; // i행에서 열 탐색 -> 즉 k는 특정 요소 위치 의미!
        if((s & (1<<k)) == 0){ // k위치의 마스킹 값이 0이면
          cur = cur * 10 + a[i][j]; // 합을 더함
        } else { // 1을 만나면
          sum += cur; // 지금까지 계산한 cur sum에 더해주고
          cur = 0; // cur 초기화
        }
      }
      sum += cur;
    }

    // 2. 세로: 1인 부분 계산
    for(int j = 0; j < m; j++){ // 세로는 열 기준 행탐색! -> 반복문 i,j위치 바꿔줌
      int cur = 0;
      for(int i = 0; i < n; i++){
        int k = i * m + j;
        if((s & (1<<k)) != 0){ // 마스킹 값이 1일 때
          cur = cur * 10 + a[i][j];
        } else{
          sum += cur;
          cur = 0;
        }
      }
      sum += cur;
    }

    ret = max(ret,sum); // 최댓값 갱신
  }

  cout << ret << '\n';

  return 0;
}