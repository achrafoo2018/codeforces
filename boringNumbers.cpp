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

ll a[(ll)1e3+7];
bool isBoaring(ll i){
	string k = to_string(i);
	For(i, k.size()){
		if((i+1) % 2 != (int) k[i] % 2)
			return false;
	}
	return true;
}
void solve(){
	int t;
	a[0] = 0;
	for(ll i=1; i < 1e3+1; i++){
		if(isBoaring(i)){
			a[i] = a[i-1] + 1;
		}else
			a[i] = a[i-1];
	}
	cin >> t;
	For(i, t){
		ll l, r;
		cin >> l >> r;
		cout << "Case #" << i+1 << ": " << a[r] - a[l-1] << endl;
	}
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
