#include <bits/stdc++.h>
using namespace std;
int n, cnt;

int main(){

  cin >> n;

  for(int i = 0; i < 7; i++){
    if(n & (1 << i)){
      cnt++;
    }
  }
  cout << cnt << '\n';

  return 0;
}