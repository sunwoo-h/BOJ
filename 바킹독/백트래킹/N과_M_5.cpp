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

  for(int i = 0; i < n; i++){
    if(!visited[i]){
      ret[depth] = a[i]; // depth 기반으로 넣어야 한다는 논리가 중요
      visited[i] = 1;
      go(depth+1);
      visited[i] = 0;
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  // 오름차순 정렬
  sort(a, a+n);
  go(0);

  return 0;
}