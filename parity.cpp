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

const int N = 1e5 + 7;
ll a[N];

int main(){
	int t;
	cin >> t;
	while(t--){
		int even = 0, odd = 0, res = 0;
		int n;
		cin >> n;
		for(int i=0; i < n; i++){
			cin >> a[i];
			if(a[i] % 2 == 0)
				even++;
			else
				odd++;
			if(i != 0){
				if(a[i] % 2 == a[i-1] % 2)
					res++;
			}
		}
		if(n == 1)
			cout << 0 << endl;
		else{
			if(abs(even-odd) > 1)
				cout << -1 << endl;
			else
				cout << res << endl;
		}
	}	
	return 0;
}
// [4, 1, 2, 3, 6]