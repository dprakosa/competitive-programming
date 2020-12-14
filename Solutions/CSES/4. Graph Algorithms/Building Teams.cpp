#include <bits/stdc++.h>
using namespace std;

int n, m, team[100005];
vector<int> v[100005];
queue<int> q;

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> m;
	fill(team+1, team+n+1, -1);
	while(m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		if(team[i] != -1) continue;
		team[i] = 0;
		q.push(i);
		while(!q.empty()) {
			int s = q.front();
			q.pop();
			for(auto u : v[s]) {
				if(team[u] == -1) {
					team[u] = (team[s]+1)%2;
					q.push(u);
				} else if(team[u] == team[s]) {
					cout << "IMPOSSIBLE\n";
					return 0;
				}
			}
		}
	}
	cout << team[1]+1 << " ";
	for(int i = 2; i <= n; i++) {
		cout << team[i]+1 << " ";
	}
}
