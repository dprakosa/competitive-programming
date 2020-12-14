#include <bits/stdc++.h>
using namespace std;

int n, m;	
const int MAXN = 100005;
bool vis[MAXN];
int dist[MAXN], path[MAXN];	
vector<int> v[MAXN];

void bfs() {
	
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	dist[1] = 1;
	path[1] = 1;
	while(!q.empty()) {
		int s = q.front();
		q.pop();
		for(auto u : v[s]) {
			if(vis[u]) continue;
			vis[u] = 1;
			dist[u] = dist[s]+1;
			path[u] = s;
			q.push(u);
		}
	}
}

void printpath(int node) {
	
	if(path[node] == node) return;
	printpath(path[node]);
	cout << node << " ";
}

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	if(!vis[n]) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << dist[n] << "\n";
	cout << "1 ";
	printpath(n);
}
