#include <bits/stdc++.h>
using namespace std;
vector<int> ret[14]; // k는 10까지 가능
int n, a[1030];

void go(int s, int e, int level){
  if(s > e) return; // start가 end보다 크면 안됨(필수 조건)
  if(s == e){ // 시작과 종료점이 같아지면 결과 배열에 넣음
    ret[level].push_back(a[s]);
    return;
  }

  int mid = (s + e) / 2; // int형이라 소수점은 버려짐
  ret[level].push_back(a[mid]);
  go(s, mid - 1, level + 1);
  go(mid + 1, e, level + 1);
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 입력 받기
  cin >> n;
  int k = (int)pow(2,n) - 1;
  for(int i = 0; i < k; i++){
    cin >> a[i];
  }

  // 레벨별 저장
  go(0,k,1);

  // 레벨별 출력
  for(int i = 1; i <= n; i++){
    for(int j : ret[i]){
        cout << j << " ";
    }
    cout << "\n";
  }

  return 0;

}