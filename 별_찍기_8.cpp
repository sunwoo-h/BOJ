#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i =1 ; i <n+1 ; i++){
    for(int k = 1; k <= i ; k++){
      cout << '*';
    }
    for(int j = 1; j <= 2*(n-i) ; j++){
      cout << ' ';
    }
    for(int k = 1; k <= i ; k++){
      cout << '*';
    }
    cout << endl;
  }
  for(int i =n-1 ; i >0 ; i--){
    for(int k = 1; k <= i ; k++){
      cout << '*';
    }
    for(int j = 1; j <= 2*(n-i) ; j++){
      cout << ' ';
    }
    for(int k = 1; k <= i ; k++){
      cout << '*';
    }
    cout << endl;
  }
  return 0;
}


// 좋은 코드... 나누지 않고 한번에 생각한 거
#include <iostream>
#include <cmath>  // abs 함수 사용
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= 2 * N - 1; ++i) {
        int stars = i <= N ? i : 2 * N - i;
        int spaces = 2 * (N - stars);

        // 왼쪽 별
        for (int j = 0; j < stars; ++j) cout << '*';

        // 공백
        for (int j = 0; j < spaces; ++j) cout << ' ';

        // 오른쪽 별
        for (int j = 0; j < stars; ++j) cout << '*';

        cout << '\n';
    }

    return 0;
}
