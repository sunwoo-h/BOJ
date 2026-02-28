#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10], ret[10];

void go(int depth, int start){
  if(depth == m){
    for(int i = 0; i < m; i++){
      cout << ret[i] << ' ';
    }
    cout << '\n';
    return;
  }
  
  int prev = -1;
  
  for(int i = start; i < n; i++){
    if(prev == a[i]) continue;
    ret[depth] = a[i];
    prev = ret[depth];

    go(depth+1, i); // 인덱스 중복 허용이기 때문에 i를 넘김!!
  }

}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a,a+n); // 정렬

  go(0,0);


  return 0;
}