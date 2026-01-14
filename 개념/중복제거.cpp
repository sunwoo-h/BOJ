#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;


// 1. map 자료구조를 이용한 중복제거
void map_func() {
  vector<int> v{1, 1, 2, 2, 3, 3};
  for(int i : v){
    if(mp[i]){
      continue;
    }else {
      mp[i] = 1;
    }
  }
  vector<int> ret;
  for(auto it : mp){
    ret.push_back(it.first); // map에서 first는 key, second는 value 의미!
  }
  for(int i : ret) cout << i << '\n';
}


// 2-1. unique() 원리
void unique_func() {
  vector<int> v;
  for(int i = 1; i <= 5; i++){
    v.push_back(i);
    v.push_back(i);
  }
  for(int i : v) cout << i << " ";
  cout << "\n";
  // 중복되지 않은 요소로 채운 후, 그 다음 이터레이터(가리키는값, 의미없는 데이터 시작가 시작되는 index)를 반환한다.
  auto it = unique(v.begin(), v.end());
  cout << it - v.begin() << '\n'; // 5 -> 즉, iterateor가 index 5를 가리키고 있음을 의미(index 5부터 의미 없는 값이라는 것을 의미!)
  // 앞에서 부터 중보고디지 않게 채운 후 나머지 요소들은 그대로 둠
  for(int i : v) cout << i << " ";
  cout << '\n';
}


// 2-2. unique() + sort() + erase()를 이용한 중복제거
void unique_func2() {
  vector<int> v {2, 2, 1, 1, 2, 2, 3, 4, 5, 5};
  sort(v.begin(), v.end()); // sort()로 오름차순 정렬
  v.erase(unique(v.begin(),v.end()), v.end()); // unique로 중복제거 후, erase로 뒤에 의미 없는 요소 제거
  for(int i : v) cout << i << " ";
}



int main() {
  cout << "1. map 자료구조를 이용한 중복제거" << '\n';
  map_func();
  cout << '\n';

  cout << "2-1. unique() 원리" << '\n';
  unique_func();
  cout << '\n';

  cout << "2-2. unique() + sort() + erase()를 이용한 중복제거" << '\n';
  unique_func2();
  return 0;
}