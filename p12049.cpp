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

	multiset<int> a;
	multiset<int> b;
	int n;

	int main(){
		int t;
		cin >> t;
		while(t--){
			a.clear();
			b.clear();
			int N, M;
			cin >> N >> M;
			set<int> all;
			for(int i=0; i < N; i++){
				cin >> n;
				a.insert(n);
				all.insert(n);
			}
			for(int i=0; i < M; i++){
				cin >> n;
				b.insert(n);
				all.insert(n);
			}
			int res = 0;
			for(auto it=all.begin(); it != all.end(); it++){
				int ac = a.count(*it);
				int bc = b.count(*it);
				res += abs(ac - bc);
			}
			cout << res << endl;
		}	
		return 0;
	}
