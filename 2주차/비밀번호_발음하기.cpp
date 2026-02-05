#include <bits/stdc++.h>
using namespace std;

string s;
int ccnt, vcnt;

bool isVowel(int idx){ // 모음인지 판단하는 함수
  return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u'); // 모음이면 true
}


int main(){
  while(true){
    cin >> s;
    if(s == "end") break; // end이면 멈추기

    ccnt = vcnt = 0; // 자음, 모음 개수 초기화
    bool flag = 0; // 판별 불타입
    bool is_include_v = 0; // 모음을 포함하는지 확인
    int prev = -1; // 이전 문자 확인용 변수

    for(int i = 0; i < s.size(); i++){
      int idx = s[i]; // 문자를 ASCII 코드로 저장

      if(isVowel(idx)){ // 모음이면
        vcnt++; 
        ccnt = 0;
        is_include_v = 1;
      } else { // 자음이면
        ccnt++;
        vcnt = 0;
      }

      if(ccnt == 3 || vcnt == 3) flag = 1; // 자음 혹은 모음이 3개 되면 flag = 1
      if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){ // ee, oo 가 아닌 경우
        flag = 1;
      }
      prev = idx; // 반복문 마지막에 prev = idx로 설정해줌으로써 다음 반복에서 prev = idx-1를 의미하게끔 설정하는 방법!
    }

    if(is_include_v == 0) flag = 1;

    if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";

  }

  return 0;
}