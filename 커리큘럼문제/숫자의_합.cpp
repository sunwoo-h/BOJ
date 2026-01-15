// 1. 틀린 풀이
// 구분자 따로 없길래
// 이렇게 나눗셈 연산자 해결로 접근 했는데 TC3에서 25자리 정수가 있어서 불가능함(정수형 범위 탈출)
// -> 25자리는 __int64로도 커버 안됨 ㅋㅋ
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int k;
  int sum = 0;
  cin >> N;
  cin >> k;
  
  for(int i = N-1 ; i >= 0 ; i--){ 
    if(k != 0){
      int t;
      t = k / pow(10,i);
      k = k - t * pow(10,i);
      sum = sum + t;
    }
    else {
      ;
    }
  }

  cout << sum << '\n';

  return 0;
}

// 2. 정답 풀이 
// string 사용.. -> 배열로 처리!!!(중요, 사고 확장)
// 너무 int에 매몰되지 말자!!
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string k;
  int sum = 0;
  cin >> N;
  cin >> k;
  
  for(int i = 0 ; i < N; i++){ 
    sum += k[i] -'0'; // 좋은 아이디어! -> '0' 을 빼줌으로써 문자형 -> 숫자형으로 변환(아스키코드)
  }

  cout << sum << '\n';

  return 0;
}