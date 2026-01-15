#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= 2*n -1 ; i++){
    int star = i <= n ? 2*n - (2*i-1) : 2*(i-n)+1;
    int space = i <= n ? i-1 : 2*n-i-1;

    for(int k = 1 ;k <= space ; k++) cout << ' ';
    for(int j = 1; j <= star ; j++) cout << '*';
    cout << endl;
  }


  return 0;
}
