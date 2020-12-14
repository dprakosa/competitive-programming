#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;
	if(n <= 3) {
		if(n == 1) cout << "1";
		else cout << "NO SOLUTION";
		return 0;
	}
	for(int i = 2; i <= n; i += 2) {
		cout << i << " ";
	}
	for(int i = 1; i <= n; i += 2) {
		cout << i << " ";
	}
}