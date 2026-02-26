#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10];

void go(int depth){
  if(depth == m){ // 기저사례
    for(int i = 0; i < m; i++){
      cout << a[i] << ' ';
    }
    cout << '\n';
    return; // 리턴 꼭 해줘야 멈춤
  }

  for(int i = 1; i <= n; i++){ // 첫 시작이 1~n까지 가능해야함
    a[depth] = i;
    go(depth+1);
  }
  
}

int main(){
  cin >> n >> m;
  go(0);

  return 0;
}