#include <bits/stdc++.h>
using namespace std;

int k;


void func(int from, int to, int n){ // 메인 로직의 인자 선정 기준 : 경로가 메인 로직에 사용되기 때문에 from to를 써줘야 함!!
  if(n == 1){ //  기저 사례
    cout << from << ' ' << to << '\n';
    return;
  }
  func(from, 6-from-to, n-1); // n-1개의 원판을 from 에서 6-from-to로 옮김(ex.1->2)
  cout << from << ' ' << to << '\n'; // n번 원판을 from 에서 to로 옮김(ex. 1->3)
  func(6-from-to, to, n-1); // n-1개의 원판을 6-from-to에서 to로 옮김(ex. 2->3)
}

int main() {
  cin >> k;
  
  cout << (int)pow(2,k) - 1 << '\n'; // 2^k -1
  func(1, 3, k);


  return 0;
}