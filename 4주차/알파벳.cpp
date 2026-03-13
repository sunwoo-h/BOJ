#include <iostream>
#include <algorithm>
using namespace std;

int R, C, ret, ny, nx;

char a[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1};

void go(int y, int x, int num, int cnt){
    ret = max(ret, cnt);

    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

        int _next = (1 << (int)(a[ny][nx] - 'A')); // 다음 칸의 알파벳을 비트로 바꾸는 부분

        if((num & _next) == 0){ // 현재까지 사용한 알파벳 집합을 의미하는 정수 num에 다음 알파벳 _next가 포함되어 있는지 확인
          go(ny, nx, num | _next, cnt + 1); // 포함 안 되어있으면 OR 연산자로 해당 비트를 포함 시켜주고 재귀호출
        }
    }
    return;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }

    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1); // 첫 출발 알파벳을 num으로 전달

    cout << ret << '\n';

    return 0;
}
