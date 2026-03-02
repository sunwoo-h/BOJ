#include <bits/stdc++.h>
using namespace std;

int n, d, p, ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙 큐 정의

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> d >> p;
    v.push_back({p,d}); // 거꾸로 저장
  }

  // 오름차순 정렬
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){ // 벡터를 순회하며
    pq.push(v[i].second); // 두 번째 요소를 넣음 -> 최소힙으로 저장됨
    if(pq.size() > v[i].first){ // !!pq의 size가 first(날짜)보다 커지면(왜? 어차피 하루에 하나밖에 못하기 때문)
      pq.pop(); // pq위에 있는 최소값 제거 
    }
  } 

  while(pq.size()){ // pq에 남은 값들(최대값만 남음) 결과에 저장
    ret += pq.top();
    pq.pop();
  }
  
  cout << ret << '\n';

  return 0;
}