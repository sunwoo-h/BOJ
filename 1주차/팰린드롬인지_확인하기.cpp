#include <bits/stdc++.h>
using namespace std;

string str, temp;

int main() {
  cin >> str;
  string temp = str; // !reverse()는 void 타입 함수라서 값을 반환하지 않기 때문에 임시 저장 필요
  reverse(temp.begin(), temp.end()); // (start: 시작 위치, end: 끝 위치)

  if(str == temp) {cout << 1;}
  else { cout << 0;}
  
  return 0;
}
