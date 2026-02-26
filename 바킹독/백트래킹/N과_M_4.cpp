#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10];

void go(int depth, int start){
  if(depth == m){
    for(int i = 0; i < m; i++) cout << a[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = start; i <= n; i++){ // start부터 n까지(이 꼴 자주나오니까 기억하기)
    a[depth] = i;
    go(depth + 1, i); // 한 출력 값에서 같은 요소 허용이라 i 그대로

    // 만약 문제가 비내림차순이 아니라 오름차순이였다면,
    // start 인자에 i가 아니라 i+1을 보내줘야 함(n과 m 2번 문제의 start보내는 부분이랑 비교!!)

    // !! start 인자 의미 !!: “다음에 뽑을 수 있는 최소 숫자” 를 기억하는 변수
    // !! start는 “이전 선택값을 기억해서 그보다 작은 숫자는 애초에 탐색하지 않게 만드는 장치”
  }
}

int main(){
  cin >> n >> m;
  go(0, 1);
  return 0;
}