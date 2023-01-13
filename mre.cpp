#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		long long a[n];
		long long mi = INT_MAX;
		for(int i=0; i < n; i++){
			cin >> a[i];
			if(a[i] < mi)
				mi = a[i];
		}
	}
	return 0;
}

