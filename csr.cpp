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


int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n % 2 == 1)
			cout << n / 2 << " " << n / 2 + 1 << endl;
		else
			cout << -n + 1 << " " << n << endl;
			 
	}	
	return 0;
}
