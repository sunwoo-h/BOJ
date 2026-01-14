#include <bits/stdc++.h>>
using namespace std;

int a[9], sum;
pair<int, int> ret;
vector<int> v;

int main(){
  // 1. 입력받기
  for(int i = 0; i < 9; i++){
    cin >> a[i];
    sum += a[i];
  }

  // 2. 9C7 -> 9C2 변환 이용
  for(int j = 0; j < 9 ; j++){
    for(int k = 0; k < j; k++){
      if(sum - a[j] - a[k] == 100){ // 빼기 로직 이용
        ret = {j,k}; // pair 이용
      }
    }
  }

  // 3. 벡터 v에 넣기
  for(int i = 0; i< 9; i++){
    if(ret.first == i || ret.second == i) continue; // 뽑힌 것들은 무시
    v.push_back(a[i]); // 안 뽑힌 것들만 벡터에 추가
  }
  sort(v.begin(), v.end()); // 정렬
  for(int i : v) cout << i << "\n";

  return 0;
}