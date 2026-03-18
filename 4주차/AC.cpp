#include <bits/stdc++.h>
using namespace std;


int t, N;
string P, order;

int main(){

  // 테스트 케이스 수
  cin >> t;

  while(t--){
    deque<int> D;
    cin >> P >> N >> order;
    int x = 0; // for 문 밖에 x초기화 해줘야 1의자리도 잘 들어감

    for(char c : order){ // 배열 분해
      if(c == '[' || c == ']') continue; // 대괄호는 무시
      if(c >= '0' && c <= '9') x = x * 10 + c -'0'; // 숫자가 나오면 현재 수*10을 한 뒤 더함
      else { // 콤마 만난 경우
        if(x > 0) D.push_back(x); // x에 값이 있으면 그건 숫자니까 D에 넣어줘
        x = 0; // x 초기화
      }
    }
    if(x > 0) D.push_back(x); // 남아 있는 거 처리
    

    // 초기에는 에러 없음, 뒤집히지 않은 상태
    bool error = false, rev = false;
    for(char a : P){
      if(a == 'R') rev = !rev; // R나오면 플래그 뒤집음
      else{ // D 나왔을떄
        if(D.empty()) { // 비어 있으면
          error = true; // 아묻따 에러
          break;
        }

        if(rev) D.pop_back(); // 뒤집힌 상태면 뒤에걸 뺌(=덱을 이용함으로써 뒤집지 않아도 로직 구현 가능)
        else D.pop_front(); // 뒤집힌 게 아니면 앞에 거 뺌
      }
    }

    if(error) cout << "error" << '\n'; // 에러 발생한 경우
    else{
      cout << '[';
      if(rev) reverse(D.begin(), D.end()); // 뒤집힌 상태면 실제로 뒤집어주기
      for(int i = 0; i < D.size(); i++){
        cout << D[i];
        if(i < D.size() - 1) cout << ','; // 중간중간 콤마 출력
      }
      cout << ']' << '\n';
    }
    


  }



  return 0;
}