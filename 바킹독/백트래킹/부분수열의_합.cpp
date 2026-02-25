#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int a[24];


void go(int cur, int tot){ // 몇번째 요소를 보고 있는지와 지금까지의 합
  if(cur == n){ // 모든 요소를 다 돌았을때
    if(tot == s) cnt++; // 합이 같아지면 cnt++
    return;
  }
  go(cur+1, tot); // 안 선택하는 경우
  go(cur+1, tot + a[cur]); // 선택하는 경우 -> 합 추가

}

int main(){
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  go(0,0);
  if(s == 0) cnt--; // !! 합이 0일 때에는 -1해줌(공집합 부분수열 제외)
  cout << cnt;

  return 0;
}