#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int space = N; // 이렇게 space 변수 따로 선언해서 써줘야 됨!! N 그대로 쓰면 오류

  for(int j = 1; j < N+1 ; j++){
    cout << string(space-1, ' '); // 문자열 반복 sting 함수 적극 사용
    int star = j;
    for(star ; star > 0 ; star--){
    cout << "* ";
    }
    cout << '\n';
    space -= 1; // for 문 내에서 다른 인자의 증감 이용하여 반복 시키고 싶을 때 자주 사용 로직
  }
}