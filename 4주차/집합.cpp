#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[11];
int x;

int main(){
  cin >> m;

  for(int i = 0; i < m; i++){
    scanf("%s %d", &s, &x); 
    if(s[0] == 'a' && s[1] == 'd') n |= (1 << x); // add
    else if (s[0] == 'r') n &= ~(1 << x); // remove
    else if (s[0] == 'c') printf("%d\n", (n & (1 << x)) == 0 ? 0: 1); // check(삼항연산자 이용)
    else if (s[0] == 't') n ^= (1 << x); // toggle
    else if (s[0] == 'a' && s[1] == 'l') n = (1 << 21) - 1; // 1빼줌으로써 다 20번째까지 전부 1로 만들어버림
    else n = 0;
  }

  return 0;
}