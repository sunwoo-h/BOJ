#include <bits/stdc++.h>
using namespace std;

int n, m, b, c;
int a[1000], psum[1000];

int main() {
  // 1. psum 만들기
  cin >> n >> m;
  for(int i = 1; i <= n; i++){ // i = 1 부터 시작하는 게 포인트
    cin >> a[i];
    psum[i] = psum[i-1] + a[i];
  }
  // 2. 구간합 구하기
  for(int i = 0; i < m; i++){
    cin >> b >> c;
    cout << psum[c] - psum[b - 1] << '\n';
  }
}