#include <bits/stdc++.h>
using namespace std;
 
int n, m, a, b;
const int c = 1e5+5;
vector<int> arr[c], res;
bool vis[c];
 
void dfs(int x) {
	
	vis[x] = 1;
	for(auto i: arr[x]) {
		if(!vis[i]) dfs(i);
	}
}
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			res.push_back(i);
			dfs(i);
		}
	}
	cout << (int)res.size()-1 << "\n";
	for(int i = 0; i < (int)res.size()-1; i++) {
		cout << res[i] << " " << res[i+1] << "\n";
	}
}
