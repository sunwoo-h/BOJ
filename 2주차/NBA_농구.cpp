#include <bits/stdc++.h>
using namespace std;
#define prev sunwoo

int n, o, A, B, asum, bsum;
string s, prev;

string print(int a){
  string d = "00" + to_string(a / 60);
  string e = "00" + to_string(a % 60);
  return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}


int changeToInt(string a){
  return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3,2).c_str()); 
}

// 이기고 있는 시간 계산
void go(int &sum, string s){ // &sum: 참조로 전달하여 원본 변수(sum)를 직접 수정
  sum += (changeToInt(s) - changeToInt(prev)); // 현재값과 이전 값 차이 계산
}

int main(){
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> o >> s; // 팀과 문자열 입력받기
    if(A > B) go(asum,s); // A팀이 이기고 있으면
    else if(B > A) go(bsum,s); // B팀이 이기고 있는경우
    o == 1 ?  A++ : B++; // !삼항연산자! -> 1팀이면 A++, 아니면 B++
    prev = s; // 다음 반복에서 비교를 위해 prev에 값 저장
  }

  // 끝값 계산 간과 주의
  if(A > B) go(asum, "48:00");
  else if(B > A)go(bsum, "48:00");

  cout << print(asum) << "\n";
  cout << print(bsum) << "\n";


  return 0;
}