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

template <class Tree_Type, class Array_Type>
class segment_tree{
public:
	int size;
	vector<Tree_Type> tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.resize(size * 2);
	}
 
	void build(int n){
        init(n);
		build(n, 0, 0, size);
	}
 
 	void build(int n, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < n)
				tree[x] = 1;
			return;
		}
		int m = (lx + rx) / 2;
		build(n, 2*x+1, lx, m);
		build(n, 2*x+2, m, rx);
		tree[x] = merge(x);
	}
 
	Tree_Type query(int k){
		return query(k, 0, 0, size);
	}

 	Tree_Type query(int k, int x, int lx, int rx){
		if(rx - lx == 1){
			return lx;
		}
		int m = (lx+rx) / 2;
		int left = tree[2*x+1];
		int right = tree[2*x+2];
		if(left > k){
			return query(k, 2*x+1, lx, m);
		}else{
			return query(k-left, 2*x+2, m, rx);
		}	
	}

	void update(int i, Array_Type v){
		update(i, v, 0, 0, size);
	}
 
	void update(int i, Array_Type v, int x, int lx, int rx){
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
		tree[x] = merge(x);
	}

	Tree_Type merge(int x){
		Tree_Type left = tree[2*x+1];
		Tree_Type right = tree[2*x+2];
		return left + right;
	}
};


void solve(){
	int n; cin >> n;
	vi arr(n);
	for(int &item : arr)
		cin >> item;
	segment_tree<int, int> st;
	st.build(n);
	vi ans(n);
	int ones = n;
	for(int i=n-1; i >= 0; i--){
		ans[i] = st.query(ones-arr[i]-1);
		st.update(ans[i], 0);
		ans[i]++;
		ones--;
	}
	for(int i : ans)
		cout << i << " ";
	cout << endl;
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
