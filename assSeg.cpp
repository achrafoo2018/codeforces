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
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
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

template <class Array_Type, class Tree_Type>
class segment_tree{
public:
	int size;
	vector<Tree_Type> tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(size * 2, {0, 0});
	}
  
	Tree_Type query(int i){
		return query(i, 0, 0, size);
	}

 	Tree_Type query(int i, int x, int lx, int rx){
		if(rx-lx == 1){
			return tree[x];
		}
		int m = (lx + rx) / 2;
		if(i < m){
			pii p = tree[x];
			pii left = query(i, 2*x+1, lx, m);
			if(p.first > left.first){
				return p;
			}else{
				return left;
			}
		}
		else{
			pii p = tree[x];
			pii right = query(i, 2*x+2, m, rx);
			if(p.first > right.first){
				return p;
			}else{
				return right;
			}

		}
	}

	void update(int l, int r, Array_Type v, int op){
		update(l, r, v, op, 0, 0, size);
	}
 
	void update(int l, int r, Array_Type v, int op, int x, int lx, int rx){
		if(rx <= l || lx >= r)	return;
		if(rx <= r && lx >= l){
			tree[x] = {op, v};
			return;
		}
		int m = (lx + rx) / 2;
		update(l, r, v, op, 2*x+1, lx, m);
		update(l, r, v, op, 2*x+2, m, rx);
	}
};


void solve(){
	int n, m; cin >> n >> m;
	segment_tree<int, pii> st;
	st.init(n);
	int j = 1;
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int l, r, v;
			cin >> l >> r >> v;
			st.update(l, r, v, j++);
		}else{
			int i; cin >> i;
			cout << st.query(i).second << endl;
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