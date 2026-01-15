#include <bits/stdc++.h>
using namespace std;
int cnt[26]; // 전역 변수로 써줘야 쓰레기 값 안 들어감

void count() {
  string str;
  cin >> str;
  
  for (char a : str) {
    cnt[a - 'a']++;
  }

  for(int i : cnt) cout << i << " ";

  return;
}


int main (){
  count();
  return 0;
}