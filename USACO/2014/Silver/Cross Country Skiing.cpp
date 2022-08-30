#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int a[505][505], N, M, level = 0;
bool way[505][505], vis[505][505];

void dfs(int x, int y) {
	
	if(vis[x][y]) return;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int x2 = x+dx[i], y2 = y+dy[i];
		if(x2 < 0 || x2 >= N || y2 < 0 || y2 >= M || abs(a[x][y]-a[x2][y2]) > level) continue;
		dfs(x2, y2);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	
	int sx = -1, sy = -1;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> way[i][j];
			if(way[i][j]) sx = i, sy = j;
		}
	}
	
	assert(!(sx == -1 && sy == -1));
	int lo = 0, hi = 1e9, ans;
	while(lo <= hi) {
		int mid = (lo+hi)/2;
		memset(vis, 0, sizeof(vis));
		level = mid;
		dfs(sx, sy);
		bool flag = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(way[i][j] && !vis[i][j]) {
					flag = 1;
					goto g;
				}
			}
		}
		g:;
		if(flag) lo = mid+1;
		else {
			ans = mid;
			hi = mid-1;
		}
	}
	cout << ans << '\n';
}
