#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, a[44], ret = INF;
string s; 

void go(int here){ //현재 here번째 행에 대해 뒤집을지 말지 결정하는 함수
  if(here == n+1){ // 기저사례 : n번째 행을 넘어가면!(=n번째 행까지 뒤집을지 말지 결정 완료됐다면) -> 현재 상태에서 T의 최소 개수 계산
    int sum = 0;
    for(int i = 1; i <= (1 << (n - 1)); i *= 2){ // 각 열을 하나씩 보는 반복문, i = 1,2,4,8.. -> n까지만 보기 떄문에 관심있는 비트들만 봄
      int cnt = 0;
      for(int j = 1; j <= n; j++) { // 모든 행을 돌면서 현재 열 i위치가 T(=1)인지 샘
        if(a[j] & i) cnt++; // true되면 1이라는 소리고, 즉 T니까 cnt++;
      }
      sum += min(cnt, n - cnt); // 열을 안 뒤집는경우, 뒤집는 경우 중 작은 값 선택
    }
    ret = min(ret, sum); // 최솟값 갱신
    return;
  }
  
  go(here + 1); // 1. 안 뒤집고 다흠행 진행
  a[here] = ~a[here]; // 2. 뒤집고
  go(here + 1); // 다음행 진행

}



int main(){
  cin >> n;
  
  // 1. 비트 연산자로 bool배열 입력받기
  for(int i = 1; i <= n; i++){
    cin >> s;
    int value = 1; // 1로 선언해줘야 처음 T나오면 비트 1로 잘 바꿈
    for(int j = 0; j < s.size(); j++){ // 문자열 s 탐색
      if(s[j] == 'T'){ // T이면,
        a[i] |= value; // 해당 위치의 비트를 1로 만듬 -> a[i] : i번째 행의 상태를 비트마스킹으로 저장
      }
      value *= 2; // *2 떄려서 다음 위치로 넘어감
    }
  }

  // 2. weird 연산자로 뒤집기
  go(1);


  // 3. 결과 출력
  cout << ret << '\n';


  return 0;
}