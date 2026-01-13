#include <bits/stdc++.h>
using namespace std;

// 1. 재귀를 이용한 조합
// 특: 순열과 달리 요소가 아닌 인덱스로 출력함(요소 중복 가능성 떄문)
int n = 5;
int k = 3;
int a[5] = {1,2,3,4,5};

void combi_recursion(int start, vector<int> b) {
  if(b.size() == k){
    for(int i : b) cout << i << " ";
    cout << '\n';
  }
  
  for (int i = start + 1 ; i < n ; i++){
    b.push_back(i);
    combi_recursion(i, b);
    b.pop_back();
  }
  return;
}

// 2. 중첩 for문을 이용한 조합
// 뽑는 수(r)가 3개 이하일 때 사용
void combi_for(){
  for(int i = 0; i < n; i ++){
    for(int j = i + 1; j < n; j++){
      for(int k = j + 1; k < n; k++){
        cout << i << " " << j << " " << k << '\n';
      }
    }
  }
  return;
}

// 아래처럼 써도 됨
// 왜냐하면 출력값이 요소 기반이 아니라 index 기반이기 때문(즉, 뭐 먼저 뽑냐 차이. 순서만 다름)
void combi_for2(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      for(int k = 0; k < j; k++){
        cout << i << " " << j << " " << k << '\n';
      }
    }
  }
}


int main() {
  vector<int> b;
  cout << "재귀를 이용한 조합 \n";
  combi_recursion(-1,b);

  cout << "중첩 for문을 이용한 조합1 \n";
  combi_for();

  cout << "중첩 for문을 이용한 조합2 \n";
  combi_for2();
}

