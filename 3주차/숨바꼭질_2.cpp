#include <bits/stdc++.h>
using namespace std;
int n, k;
int visited[100004], cnt[100004];
queue<int> q;

int arr[] = {1, -1, 2}; // 방향 3개

int bfs(int input){
  visited[input] = 1;
  cnt[n] = 1;
  q.push(input);
  while(q.size()){
    int u = q.front();
    q.pop();


    for(int i = 0; i < 3; i++){
      int nn;
      if(i == 2){
        nn = u * arr[i];
      }
      else{
        nn = u + arr[i];
      }
      if(nn >= 0 && nn <= 100003){ // 범위 설정
        if(!visited[nn]){
          q.push(nn);

          visited[nn] = visited[u] + 1;
          cnt[nn] += cnt[u];
        } else if (visited[nn] == visited[u] + 1) {
            cnt[nn] += cnt[u];
        }
      }
    }
  }
  return visited[k]-1;
}


int main(){
  // 1. 입력 받기
  cin >> n >> k;
  
  // 예외 처리
  if(n == k){ 
    puts("0"); puts("1");
    return 0; 
  } 

  // 2. bfs돌리기
  cout << bfs(n) << '\n';
  cout << cnt[k];
  

  return 0;
}