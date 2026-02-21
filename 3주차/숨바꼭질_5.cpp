#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
const int max_n = 500004;
int visited[max_n];
queue<int> q;


int main(){
  // 위치 입력받기
  cin >> n >> k; 
  
  visited[n] = 1;
  q.push(n);
  while(q.size()){
    int here = q.front(); q.pop();
    if(here == k){
      ret = visited[k];
      break;
    }
    for(int there : {here + 1, here - 1, here * 2}){
      if(there >= max_n || there < 0 || visited[there]) continue; // 범위 초과화거나 방문한 곳이면 패스
      visited[there] = visited[here] + 1;
      k += (visited[there] - 2)*(visited[there] - 1)/2; // k에 1~n-1까지 등차수열 합 더함
      q.push(there);
    }
  }

  cout << ret -1 << '\n';

  return 0;
}