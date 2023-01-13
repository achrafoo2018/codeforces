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

int getDiff(string k, char i, char j){
	int m, l;
	for(m=0; m < 26; m++){
		if(k[m] == i)
			break;
	}
	for(l=0; l < 26; l++){
		if(k[l] == j)
			break;
	}
	return abs(l-m);
}
void solve(){
	int t;
	cin >> t;
	while(t--){
		string k, s;
		cin >> k >> s;
		int ans=0;
		for(int i=1; i < s.size(); i++){
			ans += getDiff(k, s[i-1], s[i]);
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
