#include <bits/stdc++.h>
using namespace std;

int arr[26];
int arr2[26];
int cnt;

string s;

int main(){
  // 1. 문자 입력 받기
  cin >> s;

  // 2. arr 배열에 알파벳 개수 각각 저장
  for(char c : s){
    arr[c-65]++;
  }

  // 3. 알파뱃 개수가 홀수인 게 2종류 이상이면 쏘리 출력
  for(int i : arr){
    if(i % 2 == 1){
      cnt++;
    }
    if(cnt > 1){
      cout << "I'm Sorry Hansoo" << '\n';
      exit(0); // exit(0) 으로 아예 main 함수 종료
    }
  }

  // 4. 메인 로직
  for(int i = 0; i < 26; i++){ 
    if(arr[i] % 2 != 0){ // 홀수인 경우
      arr[i]--;
      arr2[i]++;
    }
    if(arr[i] != 0){ // 개수가 0이 아닌 경우
      for(int j = 0; j < arr[i] / 2; j++){
        cout << char('A' + i);
      }
    }
  }
  
  // 가운데 출력
  for(int i = 0; i < 26; i++){
    if(arr2[i] != 0){
      cout << char('A' + i);
    }
  }


  for(int i = 25; i >= 0; i--){ // 짝수 뒷부분 출력
    if(arr[i] != 0){
      for(int j = 0; j < arr[i] / 2; j++){
        cout << char('A' + i);
      }
    }
  }

  return 0;
}




// 모범답안

// #include<bits/stdc++.h> 
// using namespace std; 

// string s, ret; 
// int cnt[200], flag; 
// char mid;

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	cin >> s;
// 	for(char a : s)cnt[a]++; // count 배열 생성

// 	for(int i = 'Z'; i >= 'A'; i--){
// 		if(cnt[i]){ // 값이 있다면!!
// 			if(cnt[i] & 1){ // 홀수인 경우!!
// 				mid = char(i);flag++;
// 				cnt[i]--;
// 			}
// 			if(flag == 2)break;
// 			for(int j = 0; j < cnt[i]; j += 2){
// 				ret = char(i) + ret; 
// 				ret += char(i);
// 			}
// 		}
// 	}
// 	if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
// 	if(flag == 2)cout << "I'm Sorry Hansoo\n";
// 	else cout << ret << "\n"; 
// }