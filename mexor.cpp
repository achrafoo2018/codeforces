#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define case(i) cout << "Case #" << i << ": "


int main(){
	int t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		if((a+b) % 2 == 0)
			cout << 3 << endl;
		else
			cout << 2 << endl;
	}	
	return 0;
}
