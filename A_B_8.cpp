#include <bits/stdc++.h>
using namespace std;

int main() {
  int T,a,b;
  cin >> T;
  

  for(int i = 1 ; i < T+1 ; i++){
    cin >> a >> b;
    cout << "Case #" << i << ": " << a << " + " << b << " = " <<  a+b <<'\n';  // cout 방법
    printf("Case #%d: %d + %d = %d\n", i,a,b,a+b); // printf 방법 -> 여기선 printf가 더 깔끔하긴 함
  }

  return 0;
}