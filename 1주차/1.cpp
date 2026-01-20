#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[21], n;

int main(){
  while(scanf("%d", &n) != EOF){ // 끝날때까지 입력 받기
    ll cnt = 1, ret =1;
    while(true){
      if(cnt % n == 0){ // 나누어 떨어지면
        cout << ret << '\n'; // ret 출력하고
        break; // 반복문 멈추기
      }
      else { // 나누어 떨어지지 않으면
        cnt = (cnt * 10) + 1; // cnt 값 1-> 11 -> 111 -> 1111 -> ...
        cnt %= n; // 핵심! : 각 값마다 모듈러 연산 추가 -> 값 초과 방지
        ret ++;
      }
    }
  }

  return 0;
}