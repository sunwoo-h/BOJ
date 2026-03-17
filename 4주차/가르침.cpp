#include <bits/stdc++.h>
using namespace std;

int n, k, ret, learned;
string s;
int words[51];

// 읽을 수 있는 단어 개수 세기
int countReadable() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // 단어에 필요한 모든 알파벳을 learned가 포함하면 읽을 수 있음
        if ((words[i] & learned) == words[i]) {
            cnt++;
        }
    }

    return cnt;
}

// idx: 현재 살펴볼 알파벳 번호(0부터 살펴봄)
// cnt: 지금까지 추가로 가르친 알파벳 수
void go(int idx, int cnt) {
    // k-5개를 다 골랐으면 현재 읽을 수 있는 단어 수 확인
    if (cnt == k - 5) {
        ret = max(ret, countReadable());
        return;
    }

    // 알파벳을 다 확인했으면 종료
    if (idx == 26) return;

    for (int i = idx; i < 26; i++) {
        // 이미 배운 글자면 넘어감
        if (learned & (1 << i)) continue;

        // i번째 알파벳 배우기
        learned |= (1 << i);

        // 다음 알파벳으로 진행
        go(i + 1, cnt + 1);

        // 다시 원상복구(백트래킹)
        learned &= ~(1 << i);
    }
}

int main() {
    cin >> n >> k;

    //  5보다 작으면 암것도 못 읽음
    if (k < 5) {
        cout << 0 << '\n';
        return 0;
    }

    // 알파벳 전부 가르칠 수 있으면 모든 단어 읽기 가능
    if (k == 26) {
        cout << n << '\n';
        return 0;
    }

    // 단어 입력받고 비트마스크로 변환
    for (int i = 0; i < n; i++) {
        cin >> s;

        for (char c : s) {
            words[i] |= (1 << (c - 'a'));
        }
    }

    // antic는 무조건 배워야 하므로 미리 learned에 넣기
    learned |= (1 << ('a' - 'a'));
    learned |= (1 << ('n' - 'a'));
    learned |= (1 << ('t' - 'a'));
    learned |= (1 << ('i' - 'a'));
    learned |= (1 << ('c' - 'a'));

    // 나머지 k-5개를 고르기
    go(0, 0);

    cout << ret << '\n';

    return 0;
}