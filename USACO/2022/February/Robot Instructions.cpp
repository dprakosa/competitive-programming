#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint c = 1e9+7;
int x[45], y[45], cnt[45][(1 << 21)];
unordered_map<lint, int> m;
lint ans[45];

lint f(lint p, lint q) { return p*c+q; }

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, gx, gy;
	cin >> N >> gx >> gy;
	
	for(int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	
	for(int k = 0, idx = 0; k < (1 << (N/2)); k++) {
		lint sum_x = 0, sum_y = 0;
		for(int i = 0; i < N/2; i++) {
			if(k & (1 << i)) {
				sum_x += x[i];
				sum_y += y[i];
			}
		}
		lint val = f(sum_x, sum_y);
		if(!m.count(val)) {
			m[val] = idx;
			idx++;	
		}
		cnt[__builtin_popcount(k)][m[val]]++;
	}
	
	for(int k = 0; k < (1 << (N-N/2)); k++) {
		lint sum_x = 0, sum_y = 0;
		for(int i = 0; i < N-N/2; i++) {
			if(k & (1 << i)) {
				sum_x += x[N/2+i];
				sum_y += y[N/2+i];
			}
		}
		sum_x = gx-sum_x, sum_y = gy-sum_y;
		lint val = f(sum_x, sum_y);
		if(!m.count(val)) continue;
		lint targ = m[val];
		for(int i = 0; i <= N/2; i++) {
			ans[i+__builtin_popcount(k)] += cnt[i][targ];
		}
	}
	
	for(int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}
}
