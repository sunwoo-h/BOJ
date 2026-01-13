#include <bits/stdc++.h>
using namespace std;

// spilit() 함수 구현(암기)
vector<string> split(const string& input, string delimiter){
  vector<string> result; // 값을 담아둘 배열
  auto start = 0; // 시작 인덱스 값
  auto end = input.find(delimiter); // 구분자를 종료 인덱스값으로 설정

  while (end != string::npos) { // find 값이 없으면 string::npos 를 반환하기 때문
    result.push_back(input.substr(start, end - start)); // 키워드 배열에 넣기
    start = end + delimiter.size();
    end = input.find(delimiter, start); // s1.find(찾을 내용, 시작 위치(index)) : 시작위치 안 쓰면 기본값 0
  }

  result.push_back(input.substr(start)); // 마지막 키워드도 배열에 넣음
  return result;
}


int main(){
  vector<string> s = split("황선우,선우,황",",");
  for(string a : s) cout << a << '\n';
  return 0;
}