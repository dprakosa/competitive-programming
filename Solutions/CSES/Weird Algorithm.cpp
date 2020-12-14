#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;
	while(n > 0) {
		cout << n << " ";
		if(n == 1) break;
		(n % 2 == 0) ? n /= 2 : n = 3*n+1;
	}
	cout << "\n";
}
