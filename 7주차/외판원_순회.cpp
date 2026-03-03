#include <bits/stdc++.h>
using namespace std;
#define MAX_N 16
int n, dist[MAX_N][MAX_N];
// dp 배열 here, visited 의미
int dp[MAX_N][1 << MAX_N]; // 1 << MAX_N 은 2^n의미
const int INF = 1e9;


int tsp(int here, int visited){
  // 2. 기저사례
  if(visited == (1 << n) - 1){ // 모든 곳을 방문한 경우
    return dist[here][0] ? dist[here][0] : INF; // 초기 경로로 갈 수 있으면 가고, 안되면 INF
  }
  
  // 3. 메모이제이션
  int &ret = dp[here][visited];
  if(ret != -1) return ret;

  // 4. 로직
  ret = INF; // 최솟갑 구하는 거니까 INF로 설정
  for(int i = 0; i < n; i++){
    if(visited & (1 << i)) continue; // i번 도시를 방문했다면 continue
    if(dist[here][i] == 0) continue; // 거리가 0 이면 continue
    ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]); // i 번째 방문처리
  }
  return ret;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> dist[i][j];
    }
  }

  // 1. 초기화
  memset(dp, -1, sizeof(dp)); // dp 배열 -1로 초기화
  cout << tsp(0,1) << '\n';
  
  return 0;
}