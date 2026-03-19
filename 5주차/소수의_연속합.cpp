#include <bits/stdc++.h>
using namespace std;

bool che[4000001];
int n, a[2000001], p, lo, hi, ret, sum;

int main(){
  cin >> n;

  // 1. 에리스토테네스의 채 -> 소수 저장
  for(int i = 2; i <= n; i ++){
    if(che[i]) continue;
    for(int j = i*i; j <= n; j += i){
      che[j] = 1;
    }
  }

  for(int i=2; i<=n; i++){
		if(!che[i]) a[p++] = i; // a 배열에 소수 저장
	}  
  
  // 2. 투 포인터로 탐색(왼쪽 lo, 오른쪽 hi, 둘다 index 0 부터 시작)
  while(1){
    if(sum >= n) sum = sum - a[lo++]; // 합이 n보다 커지면 lo 값 빼고, index 증가
    else if(hi == p) break; // 소수배열 끝자락까지 가면 멈춤
    else sum = sum + a[hi++]; // 합이 n보다 작아지면 hi값 더하고, index 증가
    if(sum == n) ret++; // 카운팅
  }

  cout << ret << '\n';

  return 0;
}