#include <bits/stdc++.h>
using namespace std;

int n, ret;
vector<pair<int,int>> v;

int main(){
  cin >> n;

  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    v.push_back({b,a});
  }

  sort(v.begin(),v.end()); // 도착 시간 기준 오름차순 정렬


  // 제일 첫 번째 요소를 비교 기준값으로 설정
  int from = v[0].second;
  int to = v[0].first;

  for(int i = 1; i < n; i++){ // 두번째 요소부터 비교 시작
    if(v[i].second < to) continue;
    from = v[i].second;
    to = v[i].first;
    ret++;
  }

  cout << ret + 1 << '\n'; // 젤 첫번째 요소까지 카운팅 위해 +1 해줌

  return 0;
}