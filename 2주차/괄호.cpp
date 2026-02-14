#include <bits/stdc++.h>
using namespace std;

int t;
string s;


int main(){

  cin >> t;

  for(int i = 0; i < t; i++){
    cin >> s;
    stack<char> stk;
  
    for(char c: s){
      if(!stk.empty() && stk.top() == '(' && c == ')'){
        stk.pop();
      }
      else{
        stk.push(c);
      }
    }

    cout << (stk.empty() ? "YES" : "NO") << '\n';
  }

  return 0;
}