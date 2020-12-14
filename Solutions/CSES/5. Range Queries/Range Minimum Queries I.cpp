#include <bits/stdc++.h>
using namespace std;

int n, q;
const int MAXN = 200005;
int logg[MAXN], st[MAXN][25]; // 2^24 = 16777216 (> 1e7)

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> st[i][0];
	}
	
	logg[1] = 0;
	for(int i = 2; i <= n; i++) {
		logg[i] = logg[i/2]+1;
	}
	
	for(int i = 1; i < 25; i++) {
		for(int j = 1; j + (1 << i) <= n+1; j++) {
			st[j][i] = min(st[j][i-1], st[j + (1 << (i-1))][i-1]);
		}
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		int k = logg[r-l+1];
		cout << min(st[l][k], st[r - (1 << k) + 1][k]) << "\n";
	}
}
