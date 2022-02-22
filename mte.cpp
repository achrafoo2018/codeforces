#include "bits/stdc++.h"
 
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

int n;
map<double, int> mp;
const int N=1e5*2 + 7; 
int a[N];
void solve(){
	mp.clear();
	cin >> n;
	ll somme = 0;
	For(i, n){
		cin >> a[i];
		somme += a[i];
	}
	double mean = somme / (double)n;
	ll ans=0;
	For(i, n){
		double val = mean*2.0 - (double)a[i];
		ans += mp[val];
		mp[(double)a[i]]++;
	}
	cout << ans << endl;
	return;
}

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
