#include <bits/stdc++.h>
using namespace std;

int n;
string s;
char a[101][101];


string quard(int y, int x, int size){
  if(size == 1) return string(1, a[y][x]); // a[y][x] 문자 char -> string으로 변환
  char b = a[y][x];
  string ret = "";
  for(int i = y; i < y + size; i++){
    for(int j = x; j < x + size; j++){
      if(b != a[i][j]){ // 순수한 1 or 0이 아닌 경우
        ret += '(';
        ret += quard(y, x, size / 2); // 왼쪽 위
        ret += quard(y, x + size / 2, size / 2); // 오른쪽 위
        ret += quard(y + size / 2, x, size / 2); // 왼쪽 아래
        ret += quard(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래
        ret += ')';
        return ret;
      }
    }
  }
  return string(1, a[y][x]); // 안 걸리면 1 or 0 반환

}



int main() {
  cin >> n;

  // 연속된 값 입력받기
  for(int i = 0; i < n; i++){
    cin >> s; // string으로 입력 받고
    for(int j = 0; j < n; j++){
      a[i][j] = s[j]; // a 배열(char 타입)에 하나씩 넣기
    }
  }

  cout << quard(0,0,n) << '\n'; // y=0,x=0 출발


  return 0;
}