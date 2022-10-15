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
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
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
	int size;
	vvll tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(2*size, {0, 0, 0});
	}

	void build(vll &arr){
		init(arr.size());
		build(arr, 0, 0, size);
	}

	void build(vll &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < arr.size()){
				tree[x] = {1, arr[lx], arr[lx]};
			}
			return;
		}
		int m = (lx+rx) / 2;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		tree[x] = merge(x);
	}

	vll merge(int x){
		vll left = tree[2*x+1];
		vll right = tree[2*x+2];
		if(left == right)
			return left;
		if(left[0] == 0)
			left = right;
		if(right[0] == 0)
			right = left;
		if(left[2] != right[1]){
			return {left[0]+right[0], left[1], right[2]};
		}else{
			return {left[0]+right[0]-1, left[1], right[2]};
		}
	}

	void update(int i, int v){
		update(i, v, 0, 0, size);
	}

	void update(int i, int v, int x, int lx, int rx){
		if(rx-lx == 1){
			tree[x] = {1, v, v};
			return;
		}
		int m = (lx+rx)/2;
		if(i < m){
			update(i, v, 2*x+1, lx, m);
		}else{
			update(i, v, 2*x+2, m, rx);
		}
		tree[x] = merge(x);
	}

	ll query(int l, int r){
		return query(l, r, 0, 0, size);
	}

	ll query(int l, int r, int x, int lx, int rx){
		debug() << imie(tree[x]);
		if(rx - lx == 1) return tree[x][0];
		int m = (lx+rx) / 2;
		return tree[x][0] + query(l, r, 2*x+1, lx, m);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vll arr(n);
	For(i, n)
		cin >> arr[i];
	
	segement_tree st;
	st.build(arr);
	For(_, m){
		int i; ll x;
		cin >> i >> x;
		st.update(i-1, x);
	debug() << imie(st.tree);
		cout << st.query(0, n) << endl;
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
