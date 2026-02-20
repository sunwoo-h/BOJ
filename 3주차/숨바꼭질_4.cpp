#include <bits/stdc++.h>
using namespace std;

#define prev aaa
#define next aaaa

const int max_n = 200004;
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;  

vector<int> v; 
queue<int> q;  

int main() { 
    cin >> n >> k; 
    visited[n] = 1; 
    q.push(n);  
    while(q.size()){
        here = q.front();  
        q.pop();
        if(here == k){
            ret = visited[k]; 
            break;
        }
		for(int next : {here + 1, here - 1, here * 2}){
            if(next >= max_n || next < 0 || visited[next]) continue;  
            visited[next] = visited[here] + 1; 
            prev[next] = here; // 이 꼴 기억!
            q.push(next); 
		} 
    }   
    for(int i = k; i != n; i = prev[i]){ // 특이한 for문 -> 동생위치부터 출발
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret - 1<< '\n'; 
    reverse(v.begin(), v.end());
	for(int i : v) cout << i << ' '; 
    return 0;
}