#include <bits/stdc++.h>
using namespace std;
int n, ret;
string s;


int main() {
  // 1. n 입력받기
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> s;
    stack<char> stk; 
    for(char a : s){
      if(stk.size() && stk.top() == a){ // 문자가 stack의 top과 같으면
        stk.pop(); // stack에서 빼버림(폭발)
      }
      else stk.push(a); // 같지 않으면 stack에 넣음(처음엔 암것도 없으니까 걍 넣음)
    }
    if(stk.size() == 0) ret++;
  }

  cout << ret << '\n';
  return 0;
}