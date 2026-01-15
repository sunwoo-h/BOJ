// 방법1. for문 사용
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = n; i>0; i--){
    for(int j = i; j>0 ; j--){
      cout << "*" ;
    }
    cout << endl;
    for(int k = 1; k<=n-i+1; k++){
      cout << " ";
    }
  }

  return 0;
}


// 방법 2. setw(), string(n,c) 사용
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = n; i > 0 ; i--){
    string s(i,'*'); 
    cout << setw(n) << s << endl;
  }

  return 0;
}

