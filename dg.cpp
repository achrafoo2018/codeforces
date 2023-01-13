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


	int main(){
		int t;
		cin >> t;
		while(t--){
			ll n, m, k;
			cin >> n >> m >> k;
			ll minEdges = n/2*(n-1);
			int minK =  minEdges > m ? 2 : 1;
			if(n == 1)
				minK = 0;
			if(minK >= k-1 || m < n-1 || minEdges < m){
				cout << "NO" << endl;
			}else{
				cout << "YES" << endl;
			}
		}	
		return 0;
	}
