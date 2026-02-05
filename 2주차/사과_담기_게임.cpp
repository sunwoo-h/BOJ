#include <bits/stdc++.h>
using namespace std;

int n, m, j;
int l, r, temp, ret;


int main() {
  cin >> n >> m >> j;
  l = 1;

  for(int i = 0; i < j; i++){
    r = l + m - 1; // 사과가 떨어질 때마다 정의 해줘야 함
    cin >> temp; // 사과 위치 temp로 입력받기
    if(temp >= l && temp <= r) continue; // 사과가 바구니 범위 내에 있으면 통과
    else{ // 사과가 바구니 범위 밖에 있는 경우
        if(temp < l){ // 사과가 바구니보다 왼쪽에 있는 경우
          ret += (l - temp); // 이동 칸수만큼 ret에 저장
          l = temp; // l을 다시 temp로 저장
        }else{ // 바구나보다 오른쪽에 있는 경우
          l += (temp - r); // l을 이동
          ret += (temp - r); // 이동 칸수만큼 ret에 저장
        }

    }
    
  }
  cout << ret << '\n';

  return 0;
}