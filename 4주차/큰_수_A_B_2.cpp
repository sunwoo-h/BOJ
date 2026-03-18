#include <bits/stdc++.h>
using namespace std;

string a,b;

string add(string a, string b){
  int sum = 0; // sum은 올림 수 역할!(0 또는 1) 처음은 0으로 시작
  string ret; // 최종결과 저장

  while(a.size() || b.size() || sum){
    if(a.size()){
      sum += a.back() - '0';
      a.pop_back();
    }
    if(b.size()){
      sum += b.back() - '0';
      b.pop_back();
    }

    ret += (sum % 10) + '0'; // ret에 일의 자리만 붙여줌
    sum /= 10; // sum이 10이상이면 1남김(올림 수 1) ㄷㄷ
  }

  reverse(ret.begin(), ret.end()); // 뒤집기
  return ret;
}

int main(){
  cin >> a >> b;
  cout << add(a,b) << '\n';
}