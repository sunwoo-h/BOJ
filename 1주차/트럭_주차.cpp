#include <bits/stdc++.h>
using namespace std;

int arr[100];
int bill[3];
int stamp[6];
int cnt[3];
int sum;


void count() {
  for(int i = stamp[0]; i < stamp[1]; i++){
    arr[i]++;
  }
  for(int i = stamp[2]; i < stamp[3]; i++){
    arr[i]++;
  }
  for(int i = stamp[4]; i < stamp[5]; i++){
    arr[i]++;
  }
  return;
}

void calculate() {
  for(int i : arr) {
    for (int j = 1; j < 4 ; j++){
      if(i == j){
        cnt[i-1]++;
      }
    }
  }
  
  for(int i = 0; i < 3; i++){
    sum += bill[i]*cnt[i]*(i+1);
  }

  cout << sum << '\n';

  return;
}


int main() {
  for(int i = 0; i < 3; i++){
    cin >> bill[i];
  }
  // 그냥 int A, B, C 선언해놓고, cin >> A >> B >> C 했어도 됨
  for(int i = 0; i < 6; i++){
    cin >> stamp[i];
  }
  
  count();
  calculate();

  return 0;
}



// // 깔끔 풀이(큰돌 답안)
// #include <bits/stdc++.h>
// using namespace std;   
// int A, B, C, a, b, cnt[104], ret;
// int main(){
// 	cin >> A >> B >> C;  // 이렇게 입력받을 생각 하기
// 	for(int i = 0; i < 3; i++){
// 		cin >> a >> b; // 이렇게 입력받을 생각 하기2
// 		for(int j = a; j < b; j++)cnt[j]++; 
// 	}
// 	for(int j = 1; j < 100; j++){
// 		if(cnt[j]){ // if문 true 사고과정 익히기
// 			if(cnt[j] == 1) ret += A;
// 			else if(cnt[j] == 2)ret += B * 2;
// 			else if(cnt[j] == 3)ret += C * 3;
// 		}
// 	}
// 	cout << ret << "\n"; 
//     return 0;
// }
