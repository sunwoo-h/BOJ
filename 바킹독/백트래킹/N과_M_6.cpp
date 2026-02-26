#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[10], ret[10];

void go(int depth, int start){
  if(depth == m){
    for(int i = 0; i < m; i++){
      cout << ret[i] << ' '; 
    }
    cout << '\n';
    return;
  }


  for(int i = start; i < n; i++){
    ret[depth] = a[i]; // 결과 저장
    go(depth+1,i+1);
  }
}

int main(){
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a,a+n); // 오름차순 정렬
  
  go(0, 0);


  return 0;
}