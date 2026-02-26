#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10];

// 문제 요약
// 재귀를 이용해서 조합 푸는 문제

// void go(int depth, int start){
//   if(depth == m){ // 깊이 m이 됐을 때
//     for(int i = 0; i < m; i++){
//       cout << a[i] << ' ';
//     }
//     cout << '\n';
//     return;
//   }

//   for(int i = start; i <= n; i++){ // start(처음:1)부터 m까지
//     a[depth] = i; // 배열에 숫자 넣기
//     go(depth+1,i+1); // i + 1 해주면 후에 start가 n보다 커지는 상황이 발생하여 depth가 m까지 도달하지 못 하고 끝남
//   }

// }


void combi(int start, vector<int> v){
  if(v.size() == m){ // m가 다 뽑았으면
    for(int i : v){
      cout << i << " "; // 벡터 요소 다 출력
    }
    cout << '\n';
    return;
  }


  for(int i = start; i <= n; i++){
    v.push_back(i);
    combi(i+1,v);
    v.pop_back();
  }
}

int main(){
  // 재귀 사고(go함수)를 이용한 훌이
  cin >> n >> m;
  // go(0,1);

  // 조합 개념(combi)를 이용한 훌이
  vector<int> b;
  combi(1,b);

  return 0;
}