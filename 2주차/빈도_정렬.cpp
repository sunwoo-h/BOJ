#include <bits/stdc++.h>
using namespace std;

int n, c, a[1004];
vector<pair<int,int>> v; // (등장횟수, 숫자) 형태로 정렬하기 위한 벡터
map<int, int> mp, mp_first; // mp : 숫자별 등장 횟수 저장, mp_first : 숫자의 첫 등장 위치 저장


bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.first == b.first){ // 빈도가 같다면
    return mp_first[a.second] < mp_first[b.second]; // 먼저 등장한 숫자가 먼저 가게
  }
  return a.first > b.first; // 빈도가 다르면, 빈도 높은 순으로!
}

int main(){
  cin >> n >> c;

  // 입력 받기
  for(int i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]]++; // a[i]의 value값 +1 카운팅
    if(mp_first[a[i]] == 0){ // 처음 등장한 숫자라면(map은 첫 값이 0이라는 성질 이용)
      mp_first[a[i]] = i + 1; // 등장 위치(인덱스+1) 저장
    }
  }

  // 정렬용 벡터 만들기
  for(auto it : mp){ // 맵 순회
    v.push_back({it.second, it.first}); // {빈도, 숫자} 형태로 저장
  }

  sort(v.begin(), v.end(), cmp);

  // 출력 부분
  for(auto i : v){
    for(int j = 0; j < i.first; j++){ // first의 값이 있을 때까지만 출력!
      cout << i.second << " ";
    }
  }


  return 0;
}