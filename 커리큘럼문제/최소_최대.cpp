// 1. 배열 사용(속도 느림)
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }

  int max = arr[0];
  int min = arr[0];
  for(int j = 0 ; j < n; j++){
    if(max < arr[j]) max = arr[j];
    if(min > arr[j]) min = arr[j];
  }

  cout << min << ' ' << max;

  return 0;
}

// 2. 배열 사용x, cin으로만 구현(속도 빠름))
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n;
  int min = 10000000; // 문제 조건에 맞는 초기값 설정 중요 (-1,000,000 ≤ N ≤ 1,000,000)
  int max = -1000000; // 문제 조건에 맞는 초기값 설정 중요 (-1,000,000 ≤ N ≤ 1,000,000) -> 별 생각없이 -1 넣었다가 틀림 ㅋㅋ


  
  for(int i = 0 ; i < n; i++){
    cin >> k;
    if (min > k) min = k;
    if (max < k) max = k;
    
  }

  cout << min << ' ' << max;

  return 0;
}