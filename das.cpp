#include "bits/stdc++.h"
/***************************************************/
/***************************************************/
/******************* 3ak3ek ************************/
/***************************************************/
/***************************************************/
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; i++)

void solve(){
	int t;
	cin >> t;
	while(t--){
		int n;
		ll l, r, k;
		cin >> n >> l >> r >> k;
		vi a(n);
		For(i, n)
			cin >> a[i];
		sort(all(a));
		ll ans = 0, tot = 0;
		for(ll i : a){
			if(i >= l && i <= r){
				if(tot + i <= k){
					ans += 1;
					tot += i;
				}
				else
					break;
			}
		}
		cout << ans << endl;
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
