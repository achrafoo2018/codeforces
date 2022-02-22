#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t){
	int n = s.size();
	int m = t.size();
	if (n < m) return false;
	int p = (n - m) & 1;
	int q = 0;
	int k = 0;
	for (int i = p; i < n; i++) {
		if (k == 1) {
			k = 0;
			continue;
		}
		if (q < m && s[i] == t[q]) {
			q++;
		} else {
			k++;
		}
	}
	return q == m;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		string s, t;
		cin >> s >> t;
		if(solve(s, t)) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}
