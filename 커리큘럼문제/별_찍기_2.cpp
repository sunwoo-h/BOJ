// 방법 1. 기본 for문 사용
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 1; i<=n ; i++){
    for(int j = 1 ; j <= n -i ; j++){
      cout << " ";
    }
    for (int k = 1; k <= i; k++){
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}


// 방법 2. setw(n), string(n,c) 함수 사용
// 방법 1보다 코드 간결
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++){
    string s(i, '*');
    cout << setw(n) << s << endl; // setw(n)은 출력 필드를 n칸으로 설정해서 오른쪽 정렬이 되게 해줌
  }

  return 0;
}