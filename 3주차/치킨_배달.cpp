#include <bits/stdc++.h>
using namespace std;

int n, m, home_cnt, chicken_cnt, ret = 9800;
int a[54][54];
vector<pair<int,int>> home, chicken, combi;


void calculate(vector<pair<int,int>> v){
  int sum = 0;
  for(int i = 0; i < home_cnt; i++){
    int dist = 100;
    for(int j = 0; j < m; j++){
      int temp = abs(home[i].first - v[j].first) + abs(home[i].second - v[j].second); // 거리 계산
      dist = min(dist, temp); // 최솟값 저장  
    }
    sum += dist; // 최솟값들의 합을 sum 저장
  }
  ret = min(ret,sum);
  return;
}


void recur(int start, vector<pair<int,int>> v){
  if(v.size() == m){ // m개 다 뽑았을 때 (기저사례)
    // 로직: 다 뽑았으니까 이제 각 집마다 거리계산해서 저장해두기
    // 계산 함수 calculate()로 분기
    calculate(v);
    return;
  }

  for(int i = start; i < chicken_cnt; i++){
    v.push_back(chicken[i]);
    recur(i+1, v);
    v.pop_back();
  }
}


int main(){

  // 1. 입력받기
  cin >> n >> m ;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
      if(a[i][j] == 1){ // 집 좌표 저장
        home.push_back({i,j});
        home_cnt++; // 집 개수 저장
      }
      else if(a[i][j] == 2){ // 치킨집 좌표 저장
        chicken.push_back({i,j});
        chicken_cnt++; // 치킨집 개수 저장
      }
    }
  }

  // 2. 치킨집 중에 M개 고르는 경우의수(조합 -> 재귀 이용)
  recur(0, combi);
  

  // 3. 결과 출력
  cout << ret;

  return 0;
}