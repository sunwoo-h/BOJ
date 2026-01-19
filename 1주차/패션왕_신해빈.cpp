#include <bits/stdc++.h>
using namespace std;

int n, m;

string a, b, s;
int ret = 1;

int main(){
  // 1. n개 입력받기
  cin >> n;

  for(int i = 0; i < n; i++){
    map<string, int> mp;
    cin >> m;
    for (int j = 0; j < m; j++){
      cin >> a >> b; // 무지성 geline 말고 cin부터 생각하기!
      mp[b]++;
    }
    long long ret = 1; // 경우의 수 문제는 값이 커질 수 있기 떄문에 int보다 long 형식이 더 유리함
    for (auto i : mp){
      ret *= (i.second+1);
    }
    ret--;
    cout << ret << "\n"; // 출력값이 꼭 한번에 나올 필요는 없음
  }

  return 0;
}