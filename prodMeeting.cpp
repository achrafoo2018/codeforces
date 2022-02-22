#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<pii> pq;
		for(int i=1; i <= n; i++){
			int a;
			cin >> a;
			if(a > 0)
				pq.push({a, i});
		}
		vector<pii> res;
		while(pq.size() > 1){
			pii first = pq.top();
			pq.pop();
			pii second = pq.top();
			pq.pop();
			res.push_back({first.second, second.second});
			first.first--;
			second.first--;
			if(first.first)
				pq.push(first);
			if(second.first)
				pq.push(second);
		}
		cout << res.size() << endl;
		for(auto i : res)
			cout << i.first << " " << i.second << endl;
	}
	return 0;
}
