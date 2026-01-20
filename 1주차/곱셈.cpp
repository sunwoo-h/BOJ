#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // 타입명을 ll로 새로 정의

ll a, b, c;

ll go(ll a, ll b){
  if(b == 1) return a % c; // 기저사례

  ll ret = go(a, b / 2); // 결과값 ret에 저장
  ret = (ret * ret) % c; // ret끼리 곱해서 c로 나눈 나머지 저장

  if(b % 2){
    ret = (ret * a) % c; // 홀수인 경우엔 a를 한번 더 곱해줌
  }
  
  return ret;
}

int main() {
  cin >> a >> b >> c;
  cout << go(a,b) << '\n';

  return 0;
}