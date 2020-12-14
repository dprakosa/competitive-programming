#include <bits/stdc++.h>
using namespace std;

int n, q;
array<long long, 200005> x, dp;

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		if(i == 1) dp[i] = x[i];
		else dp[i] = dp[i-1] + x[i];
	}
	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << dp[b]-dp[a]+x[a] << "\n";
	}
}
