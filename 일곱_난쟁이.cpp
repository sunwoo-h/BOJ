#include <bits/stdc++.h>>
using namespace std;

int a[9];
pair<int, int> ret;
vector<int> v;


// 1. 조합 이용 풀이(중첩 for문)
void comb(){
  int sum = 0;
   // 1-1. 입력받기
  for(int i = 0; i < 9; i++){
    cin >> a[i];
    sum += a[i];
  }

  // 1-2. 9C7 -> 9C2 변환 이용
  for(int j = 0; j < 9 ; j++){
    for(int k = 0; k < j; k++){
      if(sum - a[j] - a[k] == 100){ // 빼기 로직 이용
        ret = {j,k}; // pair 이용
      }
    }
  }

  // 1-3. 벡터 v에 넣기
  for(int i = 0; i< 9; i++){
    if(ret.first == i || ret.second == i) continue; // 뽑힌 것들은 무시
    v.push_back(a[i]); // 안 뽑힌 것들만 벡터에 추가
  }
  sort(v.begin(), v.end()); // 정렬
  for(int i : v) cout << i << "\n";
}



// 2. 순열 이용 풀이(do while문)
void permutation(){
  // 2-1. 입력받기
  for(int i = 0; i < 9; i++){
    cin >> a[i];
  }
  // 2-2. 순열 함수 쓰기 전, 오름차순 정렬
  sort(a,a+9);
  
  // 2-3. do while문 로직
  do{
    int sum = 0; // sum은 do 안에 써야 됨(지역변수)
    for(int i = 0; i < 7; i++){
      sum += a[i];
    }
    if(sum == 100) break;
  } while(next_permutation(a,a+9));

  for(int i = 0; i < 7; i++) {
    cout << a[i] << '\n';
  }

}


int main(){
  // comb();
  permutation();
  return 0;
}