// 1. 마이 풀이
#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int length = s.length(); // 문자열 함수 length()
  int ship = length / 10; // 10의 자리 숫자
  int ill = length - 10*ship; // 1의 자리 숫자
  
  for (int i = 0 ; i < ship ; i++){
    for (int j = 10*i ; j < 10*i+10; j ++){
      cout << s[j] ;
    }
    cout << '\n';
  }
  for (int k = 10*ship ; k < 10*ship + ill ; k++){
    cout << s[k] ;
  }

  return 0;
}

// 2. 간단 풀이(딴사람 풀이)
// 내 풀이는 너무 10개씩 묶어야겠다는 생각에 매몰된듯
#include <iostream>
using namespace std;

int main()
{
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); i++)
    {

        if (i > 0 && i % 10 == 0) cout << endl;
        cout << n[i];
    }
}

// 3. 문자열 함수 substr() 사용 풀이
// 문자열 함수 많은데 써도 되는 걸 이제 알았음 ㅋㅋ
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i += 10) {
        cout << s.substr(i, 10) << '\n'; // substr 함수 : index i부터 10만큼 잘라서 리턴
    }

    return 0;
}
