#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10], visited[10], ret[10];

void go(int depth){
  if(depth == m){
    for(int i = 0; i < m; i++){
      cout << ret[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int prev = -1; // 이번 depth에서 이미 쓴 값 기억하기 위한 변수 !지역으로 선언!
  // -1로 선언하는이유는 입력값이랑 겹치지 말라고!
  for(int i = 0; i < n; i++){
    if(visited[i]) continue;
    if(prev == a[i]) continue; // 같은 depth에서 같은 값이면 스킵

    prev = a[i]; // 반복마다 prev값 갱신!!!
    ret[depth] = a[i];
    visited[i] = 1;
    go(depth + 1);
    visited[i] = 0;
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];

  sort(a, a + n);
  go(0);

  return 0;
}