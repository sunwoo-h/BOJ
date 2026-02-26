#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10], visited[10];

// 문제 요약
// next_permutation 로직을 직접 구현해서(재귀 백트래킹) 순열 구하는 문제


void go(int depth){ // depth를 인자로 받음
  // 1. 종료 조건(기저사례) -> 백트랙킹이 완전 끝났을 때 수행하는 로직(=저장한 배열 출력해야함)
  if(depth == m) {  // 끝까지 간 경우
    for(int i = 0; i < m; i++){
      cout << a[i] << ' '; // 저장해둔 배열 출력
    }
    cout << '\n';
    return;
  }

  
  // 2. 메인 로직
  for(int i = 1; i <= n; i++){ // 1부터! n까지 순회 시작(왜? 출력시 처음 시작할 수 있는 숫자들을 순회 해야하기 떄문)
    if(!visited[i]){ // 방문한 곳이 아니라면
      a[depth] = i; // 배열에 숫자 넣기

      // 약간 depth가 하나 증가할 때마다 node탐색을 거시적인 눈으로 보면 bfs처럼 퍼짐(depth마다 1개씩 추가됨)
      // 실제 탐색은 재귀라서 dfs처럼 함

      // ex. n = 3, m = 3 일때
      // depth 0에  1   2   3 
      // depth 1에 2,3 1,3 1,2
      // depth 2에 3,2 3,1 2,1
      // 총 6개!

      visited[i] = 1; // 방문 처리
      go(depth+1); // 재귀
      visited[i] = 0; // 원복(원복하는 visited배열은 전역으로 처리)
    }
  }
}

int main(){
  cin >> n >> m;
  go(0);
  return 0;
}