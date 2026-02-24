#include <bits/stdc++.h>
using namespace std;

int n, r, c, ret;

 // 2^n * 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수
int func(int n, int r, int c){
  if(n == 0){ // 기저 사례
    return 0;
  }

  int half = (int)pow(2,n-1); // 반쪽 정의 : 2^(n-1)

  // r,c의 위치에 따라 호출하는 재귀 함수가 달라짐!
  if(r < half && c < half) return func(n-1, r, c); // 1번 사각형
  if(r < half && c >= half) return half*half + func(n-1, r, c-half); // 2번 사각형(앞에 1번 사각형 개수 더해줌)
  if(r >= half && c < half) return  2*half*half + func(n-1, r-half, c); // 3번 사각형(앞에 1번,2번 사각형 개수 더해줌)
  return 3*half*half + func(n-1, r-half, c-half); // 4번 사각형(앞에 1번,2번,3번 사각형 개수 더해줌)
  // half를 빼는 건 ->  “사분면 안에서의 상대 좌표로 변환하는 것”
}


int main(){
  cin >> n >> r >> c;

  int k = (int)pow(2,n);

  cout << func(n,r,c);

  return 0;
}