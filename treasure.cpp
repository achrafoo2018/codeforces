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
	long double s1, x;
	cin >> s1 >> x;
	long double s2, p, f;
	cin >> s2 >> p >> f;
	long double a = ((x-p) / s1);
    long double b = (x / s2);
	if(s1 >= s2 || a < b){
		cout << 0 << endl;
		return;
	}
	if(a == b){
		cout << 1 << endl;
		return;
	}
	ll ans = ceil((a - b) / (f+1));
	cout << ans << endl;
}
// 1 15
// 5 1 3
// 1 2 3 4 5 
// 0 5 5 5 5 5
int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
