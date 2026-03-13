#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321; 
int n, a[14], m, temp, ret = INF, comp[14], visited[14];
vector<int> adj[11]; // 인접리스트를 벡터로 구현!


// 같은 선거구에 속한 노드들만 따라가면서 방문한 노드 개수와 인구 합을 계산하는 함수
pair<int, int> dfs(int here, int value){ // value : 어느 선거구인지(0 or 1)
  visited[here] = 1;
  pair<int, int > ret = {1, a[here]}; // first : 방문한 노드 개수, second: 인구 합

  for(int there : adj[here]){
    if(comp[there] != value) continue; // 다른 선거구에 속한 지역이면 DFS 안 감.(here이 0인데 there이 1이면 안 감)
    if(visited[there]) continue; // 방문한곳이면 스킵

    pair<int, int> _temp = dfs(there, value); // 연결된 다음 지역 dfs 결과 받아옴

    // 그 결과들 누적시킴
    ret.first += _temp.first; // 방문노드 개수 누적
    ret.second += _temp.second; // 인구 합 누적
  }

  return ret; // {이 선거구에서 방문한 노드 수, 그 노드들의 인구 합}

}



int main(){
  // 1. 입력받기
  cin >> n;
  for(int i = 1; i <= n; i++){ // 각 노드별 값 저장: 편의상 1부터 시작
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++){ // 1부터 시작
    cin >> m;
    for(int j = 0; j < m; j++){
      cin >> temp;
      adj[i].push_back(temp); // 쌍방 정보 저장
      adj[temp].push_back(i); // 쌍방 정보 저장
    }
  }


  // 2. 메인로직
  for(int i = 1; i < (1 << n) - 1; i++){ // 지역구 분간에(0또는1)비트마스킹 사용 전체 부분집합(2^n개)중에서 공집합(i=0)과 전체집합(i=2^n) 인 경우를 제외
    // 매 반복마다 초기화
    fill(comp, comp + 14, 0);
    fill(visited, visited + 14, 0);
    
    int idx1 = -1, idx2 =-1;

    //비트마스크 i를 보고 각 지역이 1번 선거구인지 0번 선거구인지 표시하는 코드
    for(int j = 0; j < n; j++){
      if(i & (1 << j)){ // i에 j번째에 비트가 켜져 있으먄(=j번째 지역이 1번 선거구에 속하면)
        comp[j + 1] = 1; // 해당 노드는 1번 선거구로 표시(인덱스 기반이라 j+1해줌)
        idx1 = j + 1; // 1번 선거구에 속한 지역 노드 기억(인덱스 기반이라 j+1해줌) -> DFS 시작점으로 쓰기 위함
      }
      else{
        idx2 = j + 1; // 이건 0번 선거구(인덱스 기반이라 j+1해줌)
      }
    }
    
    // dfs를 두 번 돌림
    pair<int,int> comp1 = dfs(idx1,1); // 선거구 1기반 dfs
    pair<int,int> comp2 = dfs(idx2,0); // 선거구 2기반 dfs

    if(comp1.first + comp2.first == n){ // 각각 방문한 노드 개수 합이 n이면(=모든 지역이 딱 두 선거구로 나뉜상태를 의미, 만약 작으면 선거구가 끊어져 있음 의미)
      ret = min(ret, abs(comp1.second - comp2.second)); // 최솟값 갱신
    }
  }

  cout << (ret == INF ? -1 : ret)<< "\n";

  
  return 0;
}