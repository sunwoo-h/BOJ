#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  if (N == 1){
    cout << '*';
  }
  else{
    for(int i = 1; i < N+1 ; i++){
      if(i != N){
        cout << string(N-i,' '); // 문자열 연결 함수 string() 사용!, 인자로 N-i 사용!
        if (i==1){
          cout << '*' << '\n';
        }
        else {
          cout << '*' << string(2*(i-1)-1, ' ') << '*' << '\n';
        }
      }
      else {
        cout << string(2*i-1,'*');
      }
    }
  }

  return 0;
}