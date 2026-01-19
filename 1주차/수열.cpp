#include <bits/stdc++.h>
using namespace std;

int n, k, temp, ret = -10000000;
int arr[1000004], psum[100001];


int main (){

  // 1.입력 받기
  cin >> n >> k;
  

  // 2. 구간합 psum 구하기
  for(int i = 1; i <= n; i++){
    cin >> temp;
    psum[i] = psum[i-1] + temp;
  }

  // 3. psum 이용해서 결과값 저장
  for(int i = k; i <= n; i++){
    ret = max(ret, psum[i] - psum[i-k]); // 슬라이딩 윈도우
  }

  cout << ret << '\n';

  return 0;
}