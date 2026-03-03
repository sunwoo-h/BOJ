#include <bits/stdc++.h>
using namespace std;

string s, b, ret;
int idx;

int main(){
  cin >> s >> b;

  for(char c : s){
    ret += c;
    // 앞에 size비교 해줘야 됨!  + 끝에서 부터 추출 방법
    if(ret.size() >= b.size() && ret.substr(ret.size() - b.size(), b.size()) == b){
      ret.erase(ret.size() - b.size(), b.size());
    }
  }
  
  if(ret.size() == 0){
    cout << "FRULA" << '\n';
  }
  else{
    cout << ret << '\n';
  }

  return 0;
}