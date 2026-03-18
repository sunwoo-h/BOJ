#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  
  bool flag = false;

  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(i < s.size() - 1 &&(s.substr(i,2) == "pi" || s.substr(i,2) == "ka" )) i++;
    else if(i < s.size() - 2 && (s.substr(i,3) == "chu")) i+=2;
    else flag = true;
  }

  if(flag) cout << "NO" << '\n';
  else cout << "YES" << '\n';

  return 0;
}