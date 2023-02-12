#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define endl '\n';
#define yes cout << "YES\n";
#define no  cout << "NO\n";
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

const int N = 1e5 + 5, M = 3e7 + 7;
int n, a[N];
int root[N], nodes, L[M], R[M], seg[M];
 
int build (int l, int r) {
	int at = nodes++;
 
	if (l == r) {
		seg[at] = a[at];
	} else {
		int m = (l + r)/2;
		L[at] = build (l, m);
		R[at] = build (m + 1, r);
		seg[at] = seg[L[at]] + seg[R[at]];
	}
 
	return at;
}
 
/* point update, v[p]++ */
int update (int i, int l, int r, int p) {
	int at = nodes++;
 
	if (l == r) {
		seg[at] = seg[i] + 1;
	} else {
		int m = (l + r)/2;
		if (p <= m) {
			L[at] = update (L[i], l, m, p);
			R[at] = R[i];
		} else {
			L[at] = L[i];
			R[at] = update (R[i], m + 1, r, p);
		}
		seg[at] = seg[L[at]] + seg[R[at]];
	}
 
	return at;
}
 
/* range query: v[A] + ... + v[B] */
int A, B;
int query (int i, int l, int r) {
	if (A > B)	return 0;
	if (r < A or l > B)	return 0;
 
 	if (l >= A and r <= B) {
		return seg[i];
	} else {
		int m = (l + r)/2;
		return query (L[i], l, m) + query (R[i], m + 1, r);
	}
}


void solve(){
	
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
