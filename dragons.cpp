#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N=2*1e5+7;
const int X=2*1e5+7;
const int Y=2*1e5+7;
ll a[N];
ll x[X];
ll y[Y];

ll posi(ll r){
	return r > 0 ? r : 0;
}

int main(){
	fastio;
	int n, m;
	cin >> n;
	for(ll i=0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for(ll i=0; i < m; i++){
		cin >> x[i];
		cin >> y[i];
	}
	sort(a, a+n);
	ll sum = 0;
	for(ll i=0; i < n; i++)
		sum += a[i];
	for(ll i=0; i < m; i++){ // loop all dragons
		ll res = 0;
		ll cw = lower_bound(a, a+n, x[i]) - a;
		if(cw >= n)
			cw -= 1;
		ll r = posi(x[i] - a[cw]) + posi(y[i] - sum + a[cw]);
		ll r2=LLONG_MAX;
		if(a[cw] > x[i])
			r2 = cw-1 > -1 ? posi(x[i] - a[cw-1]) + posi(y[i]-sum+a[cw-1]) : LLONG_MAX;
		else
			r2 = cw+1 < n ? posi(x[i] - a[cw+1]) + posi(y[i]-sum+a[cw+1]) : LLONG_MAX;
		res = min(r, r2);
		cout << res << endl;
	}
	return 0;
}
