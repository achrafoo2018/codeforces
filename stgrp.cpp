#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	ll n, k, x;
	cin >> n >> k >> x;
	ll a[n];
	for(ll i=0; i < n; i++){
		cin >> a[i];
	}	
	sort(a, a+n);
	vector<ll> dis;
	for(ll i=1; i < n; i++){
		ll diff = abs(a[i]-a[i-1]);
		if(diff > x)
			dis.push_back(diff);
	}
	sort(dis.begin(), dis.end());
	ll res = dis.size();
	for(ll i=0; i < dis.size(); i++){
		if(k == 0)
			break;
		ll q = dis[i] / x;
		ll r = dis[i] % x;
		if(r == 0)
			q--;
		if(k >= q){
			k -= q;		
			res--;
		}
	}
	cout << res+1 << endl;
	return 0;
}
