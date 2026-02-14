#include <bits/stdc++.h>
using namespace std;

string s;


int main (){

  while(true){
    getline(cin, s);
    if(s == ".") break;

    stack<char> stk;
    bool flag = true;

    for(char c: s){
      if(c == '(' || c == '[') stk.push(c); // ( 나 [ 들어오면 넣어주기
      else if(stk.size() && stk.top() == '(' && c == ')') stk.pop();
      else if(stk.size() && stk.top() == '[' && c == ']') stk.pop();
      else if(stk.empty() && (c == ')' || c == ']')){ // 아무것도 없을 때 ]나 )들어온 경우
        flag = false;
        break;
      } 
      else if(stk.size() && stk.top() == '(' && c == ']') { // ( 들어갔는데 ] 들어온 경우
        flag = false;
        break;
      }
      else if(stk.size() && stk.top() == '[' && c == ')'){ // [ 들어갔는데 ) 들어온 경우
        flag = false;
        break;
      } 

      else continue;
    }

    cout << (flag && stk.empty() ? "yes" : "no") << '\n';

  }

  return 0;
}