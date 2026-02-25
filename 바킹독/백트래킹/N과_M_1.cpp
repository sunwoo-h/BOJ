#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10], visited[10];


void go(int depth){
  // 1. 종료 조건(기저사례) -> 백트랙킹이 완전 끝났을 때 수행하는 로직
  if(depth == m) {  // 끝까지 간 경우
    for(int i = 0; i < m; i++){
      cout << a[i] << ' '; // 저장해둔 배열 출력
    }
    cout << '\n';
    return;
  }

  
  // 2. 메인 로직
  for(int i = 1; i <= n; i++){ // 1부터! 순회 시작
    if(!visited[i]){ // 방문하지 않았으면
      a[depth] = i; // 배열에 숫자 넣기

      visited[i] = 1; // 방문 처리
      go(depth+1); // 재귀
      visited[i] = 0; // 원복
    }
  }
}

int main(){
  cin >> n >> m;
  go(0);
  return 0;
}