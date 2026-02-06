#include <bits/stdc++.h>
using namespace std;

int t, a;

int main(){
  cin >> t;

  for(int i = 0; i < t; i++){
    cin >> a;
    int ret2 = 0, ret5 = 0;  // 2의 개수, 5의 개수 초기화
    
    for(int j = 2; j <= a; j *= 2){ // 2를 승수 하며
      ret2 += a / j; // 개수를 셈
    }
    for(int k = 5; k <= a; k *= 5){ // 2를 승수 하며
      ret5 += a / k;  // 개수를 셈
    }

    cout << min(ret2, ret5) << '\n';
  }

  return 0;
}