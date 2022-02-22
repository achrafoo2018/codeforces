#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n;
		pair<ll, ll> arrMin[n];
		for(int i=0; i < n; i++){
			cin >> k;
			ll minPower = LONG_LONG_MIN;
			for(int j=0; j < k; j++){
				ll armor;
				cin >> armor;
				if(armor-j+1 > minPower)
					minPower = armor-j+1;
			}
			arrMin[i] = make_pair(minPower, n);
		}
		sort(arrMin, arrMin+n);
		ll res = arrMin[0].first;
		ll nmonsters = arrMin[0].second;
		for(int i=1; i < n; i++){
			if(res+nmonsters < arrMin[i].first){
				res = arrMin[i].first-nmonsters;
			}
			nmonsters += arrMin[i].second;
		}
		cout << res << endl;
	}	
	return 0;
}
