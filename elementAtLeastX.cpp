#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)


struct segement_tree{
	int size; vpii tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(2*size, make_pair(INT_MAX, INT_MAX));
	}

	void build(vpii &arr){
		init(arr.size());
		build(arr, 0, 0, size);
	}

	void build(vpii &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < arr.size()){
				tree[x] = arr[lx];
			}
			return;
		}
		int m = (lx+rx) / 2;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		pii left = tree[2*x+1];
		pii right = tree[2*x+2];
		tree[x] = merge(left, right);
	}

	void update(int i, int v){
		update(i, v, 0, 0, size);
	}

	void update(int i, int v, int x, int lx, int rx){
		if(rx-lx == 1){
			tree[x].first = v;
			return;
		}
		int m = (lx+rx) / 2;
		if(i < m){
			update(i, v, 2*x+1, lx, m);
		}else{
			update(i, v, 2*x+2, m, rx);
		}
		pii left = tree[2*x+1];
		pii right = tree[2*x+2];
		tree[x] = merge(left, right);
	}


	int query(int v, int l){
		return query(v, l, 0, 0, size);
	}

	int query(int v, int l, int x, int lx, int rx){
		if(x < 2*size && tree[x].second >= l && tree[x].first == v){
			return tree[x].second;
		}
		if(x >= 2*size || tree[x].first < v){
			return INT_MAX;
		}
		int m = (lx+rx) / 2;
		int ans = tree[x].second >= l ? tree[x].second : INT_MAX;
		bool leftFound = 0;
		if(l < m && 2*x+1 < 2*size && tree[2*x+1].first >= v){
			int left = query(v, l, 2*x+1, lx, m);
			ans = min(ans, left);
			if(left != INT_MAX)
				leftFound = true;
		}
		if(!leftFound && 2*x+2 < 2*size && tree[2*x+2].first >= v)
			ans = min(ans, query(v, l, 2*x+2, m, rx));
		return ans;
	}


	pii merge(pii left, pii right){
		if(left.first >= right.first){
			return left;
		}else{
			return right;
		}
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vpii arr(n);
	For(i, n){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	segement_tree st;
	st.build(arr);
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int i, v; cin >> i >> v;
			st.update(i, v);
		}else{
			int x, l; cin >> x >> l;
			int ans = st.query(x, l);
			cout << (ans == INT_MAX ? -1 : ans) << endl;	
		}
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
