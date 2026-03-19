#include <bits/stdc++.h>
using namespace std;

int n, x, ret;
int a[100004];
int lo, hi;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin >> x;

  sort(a, a + n); // n까지만 해줘야 함. 10004까지 하면 앞에 0으로 그득함

  hi = n - 1;

  while(lo < hi){
    if(a[lo] + a[hi] > x) hi--;
    if(a[lo] + a[hi] < x) lo++;
    if(a[lo] + a[hi] == x) { ret++; hi--; lo++; } // 중괄호 써줘야함
  }

  cout << ret << '\n';

  return 0;
}