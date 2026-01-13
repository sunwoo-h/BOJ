#include <bits/stdc++.h>
using namespace std;

// 1. next_permutation + do while 문을 이용한 순열
// !주의 : next_permutaion은 오름차순 정렬 후 사용해야 함
// 왜? -> next_permutation() 이라는 함수가 해당 배열의 그 “다음번째 순열"을 만들어내는 함수이기 때문
void permutation_do_while() {
  cout << "정렬되어 있지 않은 배열 기반 \n";
  int  a[] = {1,3,2}; // 배열 이용
  do {
    for(int i : a) cout << i << " "; // 배열 순회 출력
    cout << '\n';
  } while(next_permutation(a,a+3));
  // 아래와 동치(배열의 주소 특성 고려)
  // next_permutation(&a[0], &a[3])
  // next_permutation(&a[0], &a[0] + 3)


  cout << "정렬된 배열 기반 \n";
  sort(a, a+3); // 오름차순 정렬 -> sort() 이용: sort[first, last)
  do{
    for (int i : a) cout << i << ' ';
    cout << '\n';
  } while (next_permutation(a,a+3));
}




// 2. 재귀(swap)를 이용한 순열
// 특 : depth 이용
int b[] = {1,2,3};

void permutation_recursion(int n, int r, int depth){
  // 기저 사례
  if(r==depth){
    for(int i = 0; i < r; i++){
      cout << b[i] << " ";
    }
    cout << "\n";
    return;
  }
  for(int i = depth; i < n; i++){
    swap(b[i], b[depth]);
    permutation_recursion(n,r,depth+1);
    swap(b[i], b[depth]);
  }
  return;
}


int main(){
  permutation_do_while();
  cout << "재귀를 이용한 순열" << '\n';
  permutation_recursion(3,3,0);
  return 0;
}


