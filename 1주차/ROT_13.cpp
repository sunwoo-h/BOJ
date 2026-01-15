#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
  getline(cin,s); // 한 줄 입력받기

  for(char a : s){
    if(a >= 65 && a <= 90){ // 대문자 범위 65~90
      if(a + 13 <= 90){
        t += a + 13;
      }
      else{ // 90 넘어가면 -26해서 다시 65로 돌아오게끔
        t += a - 26 + 13;
      }
    }
    else if(a >= 97 && a <= 122){ // 소문자 범위 97~122
      if(a + 13 <= 122){
        t += a + 13;
      }
      else{ // 90 넘어가면 -26해서 다시 97로 돌아오게끔
        t += a - 26 + 13;
      }
    }
    else{
      t += a; // 알파벳 외의 문자는 그대로 입력
    }
  }
  
  cout << t << '\n';

  return 0;
}



// // 모범 답안
// #include<bits/stdc++.h>
// using namespace std;   
// string s; 
// int main(){
//     getline(cin, s); 
//     for(int i = 0; i < s.size(); i++){
//         // 대문자인경우
//         if(s[i] >= 65 && s[i] < 97){
//             if(s[i] + 13 > 90) s[i] = s[i] + 13 - 26; 
//             else s[i] = s[i] + 13;  
//         }else if(s[i] >= 97 && s[i] <= 122){
//             if(s[i] + 13 > 122)s[i] = s[i] + 13 - 26; 
//             else s[i] = s[i] + 13;  
//         }
//         cout << s[i]; // 얘는 별도의 string 선언해서 안 받고 s그대로 수정함
//     } 
//     return 0; 
// }
