#include <bits/stdc++.h>
using namespace std;

// 팩토리얼 함수_재귀
int fact_rec(int n){
  if (n == 0 || n == 1){
    return 1;
  }
  return n * fact_rec(n-1);
}

// 팩토리얼 함수_반복문
int fact_for(int n){
  int ret = 1;
  for(int i = 1; i <= n; i++){
    ret *= i;
  }
  return ret;
}


// 피보나치 수열
int fibo(int n){
  cout << "fibo : " << n << '\n';
  if( n == 0 || n == 1) return n;
  return fibo( n -1 ) + fibo(n - 2);
}

int n = 5;
int main() {
  cout << fact_rec(n) << '\n';
  cout << fact_for(n) << '\n';
  cout << fibo(n) << '\n';
}
