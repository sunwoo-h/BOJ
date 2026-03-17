#include<bits/stdc++.h>
using namespace std;

int n, l, a[104][104], b[104][104], ret;

void solve(int a[104][104]){ // 행별 검사 함수
  for(int i = 0; i < n; i++){
    int cnt = 1;
    int j;
    for(j = 0; j < n - 1; j++){ // j+1까지 검사하니까 범위는 n-1까지!
      if(a[i][j] == a[i][j + 1]) cnt++; // 같은 레벨이면 cnt 증가
      else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1; // 하나 차이 오르막길 만났는데, cnt가 l보다 크거나 같으면 다리 놓기 가능 -> cnt 다시 설정
      else if(a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; // 하나 차이 내리막길 만났는데, cnt가 0보다 크면 -> 다리 놓을 수 있음 -> cnt 다시 설정
      else break; // 그 외의 상황은 전부 중단
    }
    if(j == n - 1 && cnt >= 0) ret++; // 끝까지 도달했을 때, cnt가 0보다 크거나 같으면 결과에 추가
  }
  return;
}


int main(){
  cin >> n >> l;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &a[i][j]);
      b[j][i] = a[i][j]; // 대칭행렬 구하기
    }
  }

  solve(a);
  solve(b);

  cout << ret << "\n";

  return 0;
}