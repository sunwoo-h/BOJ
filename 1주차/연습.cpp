#include <bits/stdc++.h>
using namespace std;

int a[9];

void permutation_recursion(int n, int r, int depth){
  if(r == depth){
    int sum = 0;
    for(int i = 0; i < r; i++){
      sum += a[i];
    }
    if(sum == 100){
      sort(a,a+r);
      for(int i = 0; i < 7; i++){
        cout << a[i] << '\n';
      }
      exit(0);
    }
  
  }
  for(int i = depth; i < n; i++){
    swap(a[i], a[depth]);
    permutation_recursion(n,r,depth+1);
    swap(a[i], a[depth]);
  }
}


int main(){
  for(int i = 0; i < 9; i++){
    cin >> a[i];
  }
  permutation_recursion(9,7,0);
  return 0;
}
