#include <bits/stdc++.h>
using namespace std;

string s;
int maks = 0, length;

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> s;
	int idx = 0;
	while(idx < (int)s.size()) {
		if(idx == 0) {
			length = 1;
		} else {
			if(s[idx] == s[idx-1]) length++;
			else length = 1;
		}
		maks = max(maks, length);
		idx++;
	}
	cout << maks << "\n";
}