#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, ret;
vector<pair<ll,ll>> v;
vector<ll> v2;



int main(){
  cin >> n >> k;
  
  for(int i = 0; i < n; i++){
    int a, b; // 무게, 가격
    cin >> a >> b;
    v.push_back({a,b});
  }
  
  for(int i = 0; i < k; i++){
    int c;
    cin >> c;
    v2.push_back(c);
  }

  sort(v.begin(), v.end()); // 보석 무게 기준 오름차순
  sort(v2.begin(),v2.end()); // 가방 오름차순

  priority_queue<ll> pq; // 최대힙 우선순위큐

  int j = 0; // “보석을 한 번만 스캔하기 위한 포인터” 역할 -> 이미 탐색한 보석은 다시 안 봄
  for(int i = 0; i < k; i++){ // 가방 탐색
    while(j < n && v[j].first <= v2[i]){ // 보석 무게가 가방보다 작거나 같은 것들은
      pq.push(v[j++].second); // pq에 가치를 저장 하고 j를 +1 함!
    }
    if(pq.size()){ // pq에 값이 있으면
      ret += pq.top(); // 저장된 보석들 중 가장 최대 가치를 결과값에 더하고
      pq.pop(); // 뺌!
    }
  }


  cout << ret << '\n';

  return 0;
}