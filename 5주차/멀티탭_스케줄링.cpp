#include<bits/stdc++.h>
using namespace std;

int n, k, a[104], visited[104], cnt;
const int INF = 987654321;

vector<int> v;

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
      cin >> a[i];
    }

    for(int i = 0; i < k; i++){
        if(!visited[a[i]]){  // 멀티탭에 안 꽂혀있는 경우

            // 1. 꽉 차있으면(페이징 알고리즘)
            if(v.size() == n){ 
                int last_idx = 0; // 가장 늦게 다시 쓰이는 위치
                int pos; // 뽑을 기기번호

                for(int _a : v){ // 꽂혀있는거 하나씩 검사
                    int here_pick = INF; // 앞으로 다시 안쓰이면 INF유지

                    // 현재 시점 이후에 언제 다시 쓰이는지 찾기
                    for(int j = i + 1; j < k; j++){ 
                        if(_a == a[j]){ // 쓰이면 here_pick에 인덱스 저장
                            here_pick = j;
                            break;
                        }
                    }

                     // 더 늦게 쓰이거나 아예 안 쓰이면 교체 후보로 선택
                    if(last_idx < here_pick){
                        last_idx = here_pick;
                        pos = _a; // 뽑을 기기번호에 인덱스 저장
                    }
                }

                visited[pos] = 0; // 선택된 기기 제거
                cnt++;
                v.erase(find(v.begin(), v.end(), pos)); // 벡터에서도 제거
            }

            // 2. 멀티탭 공간 있으면(걍 꽂으면 됨)
            // 현재 기기 꽂기
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }

    cout << cnt << "\n";

    return 0;
}
