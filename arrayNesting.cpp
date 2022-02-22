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
	while(1){
		int N, M;
		set<int> jack;
		cin >> N >> M;
		if(N == 0 && M == 0)
			break;
		for(int i=0; i < N; i++){
			ll cd;
			cin >> cd;
			jack.insert(cd);
		}
		ll res = 0;
		for(int i=0; i < M; i++){
			ll cd;
			cin >> cd;
			if(jack.find(cd) != jack.end())
				res++;
		}
		cout << res << endl;
	}
	return 0;
}
