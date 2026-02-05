#include <bits/stdc++.h>
using namespace std;   
int n; 
vector<string> v; 
string s, ret;


void go(){   
	while(true){  
    // 중요! front같은 문자열 함수 쓸 때 반드시 앞에 size() 체크 해줘야 함.
    // 안 그럼 참조 에러 남!
		if(ret.size() && ret.front() == '0')ret.erase(ret.begin()); // ret의 맨 앞이 0 이면 0제거!
		else break;
	}

	if(ret.size() == 0) ret = "0";  // ret값이 없으면(위에서 0이 다 지워지는 경우-> Ex.0000) ret은 0으로 판정
	v.push_back(ret); // 벡터에 저장
	ret = "";  // ret 초기화
}


bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}


int main () {
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s;
    ret = ""; // 결과 저장용 ret
		for(int j = 0; j < s.size(); j++){
			if(s[j] < 65) ret += s[j]; // 숫자면 ret에 저장
			else if(ret.size()) go();  // 문자가 등장하고, ret에 값이 있으면 go()함수 호출
		}
		if(ret.size()) go(); // 마지막이 숫자로 끝난 경우 남은 ret 처리
	}

	sort(v.begin(), v.end(), cmp);

	for(string i : v)cout << i << "\n"; 
	return 0;
}