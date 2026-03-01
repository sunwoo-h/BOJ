#include <bits/stdc++.h>
using namespace std;
int ret, totalAmount = 12100;

int main() {
	// 각 화폐 단위와 개수를 저장한 벡터
	vector<pair<int, int>> currency = {{10000, 5}, {5000, 5}, {1000, 5}, {100, 5}};

	// 내림차순으로 정렬
	sort(currency.rbegin(), currency.rend()); // r은 reverse 의미!
	
	for (auto &c : currency) {
		while (totalAmount >= c.first) {
			totalAmount -= c.first; // 총 금액에서 뽑은 지폐 금액 뺌
			c.second--; // 지폐 개수 감소
			ret++; // 총 개수 증가
		}
	}
	if(totalAmount == 0) cout << ret << '\n';
	else cout << "불가능합니다. \n";
	return 0;
}