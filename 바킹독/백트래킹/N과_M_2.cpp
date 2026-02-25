#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10];


void go(int depth, int start){
  if(depth == m){
    for(int i = 0; i < m; i++){
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = start; i <= n; i++){
    a[depth] = i;
    go(depth+1,i+1);
  }

}

int main(){
  cin >> n >> m;
  go(0,1);

  return 0;
}