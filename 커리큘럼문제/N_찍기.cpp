// endl vs '\n' 실행속도 체감 문제
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  for (int i=1; i < N+1 ;i++) cout << i << '\n'; // endl 쓰면 '시간초과' 발생함 ㄷㄷ
  return 0;
}