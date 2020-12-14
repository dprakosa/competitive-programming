#include <bits/stdc++.h>
using namespace std;

int n, pre, x;
long long cnt = 0;

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(i > 0) {
			if(pre > x) {
				cnt += pre - x;
				x = pre;
			}
		}
		pre = x;
	}
	cout << cnt << "\n";
}