#include <bits/stdc++.h>
using namespace std;

int arr[26]; // 알파벳 카운트 배열
int n, cnt;
string name[154];

int main() {
  cin >> n; // 입력할 이름의 개수
  for(int i = 0; i < n; i++){ // 이름 입력받기
    cin >> name[i];
  }

  for(int i = 0; i < n; i++){ // 이름 하나씩 순회. 주의 : 여기서 for(string s : name) 해버리면 빈 배열도 다 돌아버림
    char a = name[i][0];
    arr[a - 'a']++; // 알파벳 cnt 증가
  }

  for(int i = 0; i < 26; i++){
    if(arr[i] >= 5){
      cout << char(i+97); // a의 ASCII 코드가 97인 점을 이용해서 알파벳 출력
    }
    else { 
      cnt++;
    }
  }
  if(cnt == 26) cout << "PREDAJA"; // 5 이상인 알파벳이 하나도 없으면 출력

  return 0;
}


// // 모범답안(확실히 깔끔)
// #include<bits/stdc++.h>
// using namespace std; 
// int n, cnt[26]; 
// string s, ret; 
// int main(){
//     cin >> n; 
//     for(int i = 0; i < n; i++){
//         cin >> s; 
//         cnt[s[0] - 'a']++; // 이렇게 이름 입력받음과 동시에 cnt 셀 수도 있음. 난 이걸 굳이 두 개로 나눠버린겨ㅜㅜ(첫 번째 두 번째 for 문 범위 같아서 합칠 생각 했어야 함)
//     }
//     for(int i = 0; i < 26; i++)if(cnt[i] >= 5) ret+=  i + 'a'; 
//     if(ret.size()) cout << ret << "\n"; // size() 함수 이용해서 ret에 값이 있으면(true), ret을 출력하고,
//     else cout << "PREDAJA" << "\n"; // 그게 아니면 PREDAJA 출력
// }
