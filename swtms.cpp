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

struct segment_tree{
	int size;
	vll tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(size * 2, 0LL);
	}
 
	void build(vll &arr){
        init(arr.size());
		build(arr, 0, 0, size);
	}
 
	long long query(int l, int r){
		return query(l, r, 0, 0, size);
	}
 
	void update(int i, int v){
		update(i, v, 0, 0, size);
	}
 
	void build(vll &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < arr.size()){
				tree[x] = arr[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		tree[x] = tree[2*x+1] + tree[2*x+2];
	}
 
	long long query(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return 0LL;
		if(lx >= l && rx <= r) return max(tree[x], 0LL);
		int m = (lx + rx) / 2;
		ll left = query(l, r, 2*x+1, lx, m);
		ll right = query(l, r, 2*x+2, m, rx);
		ll ans = max(left, 0LL) + max(right, 0LL);
		return ans;
	}
 
	void update(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if(i < m){
			update(i, v, 2*x+1, lx, m);
		}else{
			update(i, v, 2*x+2, m, rx);
		}
		tree[x] = tree[2*x+1]+ tree[2*x+2];
	}
};


void solve(){
	int n, m; cin >> n >> m;
	vll arr(n);
	for(auto &i : arr)
		cin >> i;
	segment_tree st;
	st.build(arr);
	cout << st.query(0, n) << endl;
	while(m--){
		int i, v; cin >> i >> v;
		st.update(i, v);
		cout << st.query(0, n) << endl;
		debug() << imie(st.tree);
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
