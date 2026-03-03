#include <bits/stdc++.h>
using namespace std;

int n, ret;
vector<pair<int,int>> v;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int a,b;
    cin >> a >> b;
    v.push_back({a,b});
  }

  sort(v.begin(), v.end()); // 오름차순 정렬

  int realTime = v[0].first + v[0].second; // 처음 소 끝나는 시간을 초기 realTime으로 설정!

	for(int i = 1; i < v.size(); i++){
		realTime = max(realTime, v[i].first); // realTime과 뒷 소의 시작시점을 max 연산해서 realTime 갱신
		realTime += v[i].second; // 갱신한 realTime에 뒷 소의 소요시간을 더함
	}
	cout << realTime << "\n"; 


  return 0;
}