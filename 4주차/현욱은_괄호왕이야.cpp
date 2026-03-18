#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n, d[200001], ret, cnt; 
string s;
stack<int> stk;

int main() {
	cin >> n >> s;   

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') stk.push(i);  
		else if(stk.size()){ 
				d[i] = d[stk.top()] = 1; // 괜찮은 문자열은 d배열에 1로 마스킹
				stk.pop(); 
		}
	} 

  // d배열에서 1인 길이 세기
	for (int i = 0; i < n; i++){
		if (d[i]) {
			cnt++;
      ret = max(ret, cnt); // 최댓값 갱신
		}else cnt = 0;  
	}
	cout << ret << "\n"; 
}

// 다룬 풀이
// #include <bits/stdc++.h>

// using namespace std;

// int n, cnt, ret;
// string str;
// stack<int> s;

// int main() {
//   cin >> n >> str; 
//   s.push(-1); // 처음에 -1을 넣음

//   for (int i = 0; i < n; i++) {
//     if (str[i] == '(') s.push(i); // 인덱스 번호를 넣음 -> 인덱스 번호를 이용해 길이를 구하는 거라 -1을 넣어야 함
//     if (str[i] == ')') {
//       s.pop();
//       if (!s.empty()) {
//       	ret = max(ret, i - s.top()); // 최댓값 갱신
// 	    } else { 
// 	  	s.push(i); // 인덱스 값을 넣어서 다음 계산의 분기점으로 삼음
// 	    } 
//   	}
//   }
//   cout << ret << '\n';

//   return 0;
// }  