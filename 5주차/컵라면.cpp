#include <bits/stdc++.h>
using namespace std;

int n, ret, a, b;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    v.push_back({a,b});
  }

  sort(v.begin(), v.end()); // 벡터 오름차순 정렬

  for(int i = 0; i < n; i++){
    pq.push(v[i].second);
    if(pq.size() > v[i].first){
      pq.pop();
    }
  }

  while(pq.size()){ // pq에 남은 값들(최대값만 남음) 결과에 저장
    ret += pq.top();
    pq.pop();
  }
  
  cout << ret << '\n';

  

  return 0;
}