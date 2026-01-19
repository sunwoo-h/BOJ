#include <bits/stdc++.h>
using namespace std;

int n, m; // 1 < n,m < 100,000
string s;
map<string, int> mp;
map<int, string> mp2;
string a[100004];

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
  // 1. n, m 입력받기
  cin >> n >> m;

  // 2. 포켓몬 이름 입력받기
  for(int i = 0; i < n; i++){
    cin >> s; // string 입력받고
    mp[s] = i + 1; // mp에 넣기
    mp2[i + 1] = s; // mp2에 넣기(시간복잡도 O(log(N))
    // a[i + 1] = s; // 이렇게 배열 써도 됨(시간복잡도 O(1))
  }

  // 3. 맞춰야하는 포켓몬 입력받고 변환 출력하기
  for(int i = 0; i < m; i++){
    cin >> s; // 입력받고
    if(atoi(s.c_str()) == 0){ // 문자열이면
      cout << mp[s] << "\n"; // 숫자 출력
    }
    else{ // 숫자면
      cout << mp2[atoi(s.c_str())] << "\n"; // 문자열 출력
      // cout << a[atoi(s.c_str())] << "\n" // 배열로 출력하는 경우(시간 복잡도 O(1)
    }
  }

  return 0;
} 