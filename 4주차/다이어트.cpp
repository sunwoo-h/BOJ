#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, mp, mf, ms, mv;
int b, c, d, e, ret = INF, sum;
// b, c, d, e : 현재 선택한 조합의 영양소 총합
// sum : 현재 선택한 조합의 총 비용, ret : 지금까지 찾은 최소 비용

struct A{
  int mp, mf, ms, mv, cost;
}a[16]; // 구조체 배열 정의

map<int, vector<vector<int>>> ret_v; // 재료의 결과를 담아두는 벡터

int main(){
  cin >> n;
  cin >> mp >> mf >> ms >> mv; // 하한값
  for(int i = 0; i < n; i++){
    cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
  }

for(int i = 1; i < (1 << n); i++){ // !!조합 모든 경우의 수 확인(재료를 고르는 모든 경우의 수) 1부터인 이유는 0은 아무 재료도 고르지 않은 경우라 굳이 필요 없기 때문
  b = c = d = e = sum = 0; // 매 조합마다 초기화
  vector<int> v; // 매 조합바다 재료 번호 담아둘 임시 벡터

  for(int j = 0; j < n; j++){ // j는 0부터 n-1까지(재료 한개씩 탐색), 
    if(i & (1 << j)){ // i에서 j번째 비트가 켜져있는지(=해당 재료를 쓰는지) 확인! 
      // 비트가 켜져 있으면(=해당 재료를 쓰면)
      // 1. 켜져있으면 j+1(문제조건에 재료 번호가 1부터 시작이라서 +1해줌) v벡터에 저장
      v.push_back(j+1); 
      // 2. 각 재료들, 가격의 합 저장하기
      b += a[j].mp; 
      c += a[j].mf;
      d += a[j].ms; 
      e += a[j].mv; 
      sum += a[j].cost;
    }
  }

  if(b >= mp && c >= mf && d >= ms && e >= mv){ // 바로 위에서 계산한 영양소들의 값이 하한값보다 더 크면
    if(ret >= sum){ // 최솟값인지 확인해준 뒤
      ret = sum; // ret 갱신
      ret_v[ret].push_back(v); // 몇 번째 재료인지 출력하기 위한 ret_v 벡터에 재료번호 저장
    }
  }
}

if(ret == INF) cout << -1 << '\n'; // INF그대로면 조건을 만족하는 조합이 하나도 없다는 뜻이니(=재료 없음) -1출럭
else {
  sort(ret_v[ret].begin(), ret_v[ret].end()); // 최소 비용(ret)인 조합들의 사전순 정렬
  cout << ret << '\n'; // 최소 결과 출력
  for(int a : ret_v[ret][0]){ // 최소 비용의 조합들중 가장 첫번째 조합 출력(위에서 사전순 정렬 해줬기 때문)
    cout << a << " ";
  }
}

  return 0;
}