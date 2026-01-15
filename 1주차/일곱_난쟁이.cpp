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
    int sum = 0; // sum은 do 안에 써야 됨(지역변수) + 0으로 초기화 해줘야 함. 아니면 가비지 값 들어감
    for(int i = 0; i < 7; i++){
      sum += a[i];
    }
    if(sum == 100) break;
  } while(next_permutation(a,a+9));

  for(int i = 0; i < 7; i++) {
    cout << a[i] << '\n';
  }

}


// 3. 재귀 순열 풀이
void permutation_recursion(int n, int r, int depth){
  if(r == depth){ // 3-1. 기저사례 작성(r==depth)
    int sum = 0;
    for(int i = 0; i < r; i++){
      sum += a[i];
    }
    if(sum == 100){
      sort(a,a+r);
      for(int i = 0; i < 7; i++){
        cout << a[i] << '\n';
      }
      exit(0); // 3-2. 중요: 이건 경우의 수가 많기 때문에 return 말고 exit 써서 main함수 종료 시켜야 함!
    }
  
  }
  for(int i = depth; i < n; i++){ // 3-2. 순열 재귀 함수 구현
    swap(a[i], a[depth]);
    permutation_recursion(n,r,depth+1);
    swap(a[i], a[depth]);
  }
}

int main(){
  // comb();
  // permutation();
  for(int i = 0; i < 9; i++){
    cin >> a[i];
  }
  permutation_recursion(9,7,0);
  return 0;
}