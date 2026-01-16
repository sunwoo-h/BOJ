#include <bits/stdc++.h>
using namespace std;
int n, temp;
string s, t;
string front, back;

int main() {
  cin >> n >> s;
  

  // 1. 앞, 뒤 문자열 추출
  int temp = s.find('*'); // * 위치 찾기
  front = s.substr(0,temp); // * 앞 문자열 추출
  back = s.substr(temp+1); // * 뒤 문자열 추출
  // for(int i = 0; i < s.size(); i++){ // 내가 처음 쓴 코드 ㅋㅋ
  //   if(s[i] == 42){
  //     temp = i; // temp에 *위치 저장
  //     break;
  //   }
  // }
  // for(int i = 0; i < temp; i++){
  //   front += s[i]; // front에 *앞까지 문자열 저장
  // }

  // for(int i = temp + 1; i < s.size(); i++){
  //   back += s[i]; // back에 *뒤부터 문자열 저장
  // }


  // 2. 파일 이름 분석
  for(int i = 0; i < n; i++){ // 파일 이름 입력받기
    cin >> t;
    if(front.size() + back.size() > t.size()){
      cout << "NE\n"; // 입력받은 문자열보다 추출된 문자열들의 합이 더 클 때 NE 출력
    }
    else{
      if(t.substr(0, front.size()) == front && t.substr(t.size() - back.size()) == back){
        cout << "DA\n";
      }
      else cout << "NE\n";
    }
  }
  
  return 0;
}