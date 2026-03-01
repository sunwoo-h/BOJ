#include <bits/stdc++.h>
using namespace std;

int from, to, n, idx = 0, ret = 1;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  vector<pair<int,int>> v;

  for(int i = 0; i < n; i++){
    cin >> from >> to;
    v.push_back({to,from}); // 끝나는 시간을 기준으로 오름차순 정렬 위해 뒤집이서 저장
  }

  sort(v.begin(),v.end()); // pair는 first 기준으로 정렬

  from = v[0].second;
  to = v[0].first;

  for(int i = 1; i < n; i++){ // 저장한 벡터 순회
    if(v[i].second < to) continue; // 도착시간보다 출발시간이 빠르면 패스
    // 그게 아니면 from, to 재정의
    from = v[i].second;
    to = v[i].first;
    ret++;
  }
  
  cout << ret << '\n';


  return 0;
}