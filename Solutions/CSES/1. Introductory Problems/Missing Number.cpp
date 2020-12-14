#include <bits/stdc++.h>
using namespace std;

long long n, x, sum = 0;

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> x;
		sum += x;
	}
	cout << n*(n+1)/2 - sum << "\n";
}