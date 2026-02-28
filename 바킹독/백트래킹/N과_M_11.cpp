#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10], ret[10];

void go(int depth){
  if(depth == m){
    for(int i = 0; i < m; i++){
      cout << ret[i] << ' ';
    }
    cout << '\n';
    return;
  }
  
  int prev = -1;
  
  for(int i = 0; i < n; i++){
    // 9번과 다른점 -> visited 처리를 없앰
    // 이로써 순열은 중복인덱스 허용 처리를 visited 배열이 하고 있음을 알 수 있음
    if(prev == a[i]) continue;
    ret[depth] = a[i];
    prev = ret[depth];

    go(depth+1);
  }

}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a,a+n); // 정렬

  go(0);


  return 0;
}