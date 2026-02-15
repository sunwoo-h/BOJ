#include <bits/stdc++.h>
using namespace std;

int n, r, temp, root;
vector<int> adj[54];


int dfs(int here){
  int ret = 0; // 결과
  bool hasChild = false; // child 유무
  
  for(int there : adj[here]){ // 인접 리스트 순회
    if(there == r) continue; // 지울 노드면 반복문 탈출 -> !! 지울 노드의 인접행렬은 순회 안한다는 의미!!!
    ret += dfs(there); // 자식 노드 총 개수 합함
    hasChild =  true; // 자식 있음
  }
  if(!hasChild) return 1; // 자식 없으면 1개 카운팅
  return ret;
}


int main(){
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> temp;
    if(temp == -1) root = i; // -1을 입력받으면 해당 노드를 루트로 지정
    else adj[temp].push_back(i); // 그게 아니면, 해당 입력에 노드 붙이기
  }

  cin >> r; // 삭제할 노드 입력받기

  if(r == root){
    cout << 0 << '\n'; // 예외처리: 루트 지우면 0출력 
    return 0; // 끝냄
  }

  cout << dfs(root) << "\n"; // !! 루트부터 탐색 !! 

  return 0;
}