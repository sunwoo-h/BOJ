#include <bits/stdc++.h>
using namespace std;

int n, m, arr[15004], cnt;


// 재귀를 이용한 조합 풀이
void combi(int start, vector<int> v){ 
  if(v.size() == 2){ // 기저사례
    int b = arr[v[0]];
    int c = arr[v[1]];

    if(b + c == m)cnt++;
    return;
  }

  for(int i = start + 1; i < n; i++){
    v.push_back(i);
    combi(i, v);
    v.pop_back(); 
  }
}


int main() {

  // 1. n,m 입력받기
  cin >> n >> m;

  // 2. n개의 숫자 입력받기
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  // // 3. 메인 로직
  // if(m > 200000) cout << 0 << '\n'; // 20만(최대) 이상이 넘어가면 0출력
  // else{
  //   for(int i = 0; i < n; i++){
  //     if(arr[i]) { // 배열 값이 0이 아닌 부분만 탐색
  //       for(int j = 0; j < i; j++){
  //         if(arr[i] + arr[j] == m){
  //           cnt++;
  //         }
  //       }
  //     }
  //   }
  // }


  // 조합 풀이
  vector<int> v;
  combi(-1, v);

  cout << cnt << '\n';


  return 0;
}