#include <bits/stdc++.h>
using namespace std;

int n;
long long ret; // 부분 수열 개수 크기가 커질 수도 있으니까 long long 타입!
int a[100004];
int cnt[100004];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int hi = 0;

    for(int lo = 0; lo < n; lo++){
        // hi를 가능한 만큼 오른쪽으로 늘림
        while(hi < n && cnt[a[hi]] == 0){
            cnt[a[hi]]++;
            hi++;
        }

        // 현재 lo에서 시작하는 가능한 부분수열 개수
        ret += (hi - lo);

        // lo가 다음으로 이동할 거니까 현재 lo 원소 제거
        cnt[a[lo]]--;
    }

    cout << ret << '\n';

    return 0;
}