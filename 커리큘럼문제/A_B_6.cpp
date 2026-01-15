#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a,b;
  for(int i = 1; i <= N ; i++){
    scanf("%d,%d",&a,&b);
    cout << a+b << '\n';
  }
  return 0;
}