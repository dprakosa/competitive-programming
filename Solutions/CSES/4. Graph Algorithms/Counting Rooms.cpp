#include <bits/stdc++.h>
using namespace std;
 
char arr[1005][1005];
int n, m, cnt;
string str;
 
void f(int a, int b) {
	
	arr[a][b] = '#';
	pair<int, int> p[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	for(int i = 0; i < 4; i++) {
		int c = a + p[i].first, d = b + p[i].second;
		if(arr[c][d] == '.' && c >= 0 && c < n && d >= 0 && d < m) f(c, d);
	}
}
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> str;
		for(int j = 0; j < str.length(); j++) arr[i][j] = str[j];
	}
	cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {	
			if(arr[i][j] == '.') {
				cnt++;
				f(i, j);
			}
		}
	}
	cout << cnt;
}
