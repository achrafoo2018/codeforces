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
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

int n, k;
vvi ranks;

bool check(int cow1, int cow2){
	int s1 = 0, s2 = 0;
	For(i, k){
		int idx1, idx2;
		For(j, n){
			if(ranks[i][j] == cow1) idx1 = j;
			if(ranks[i][j] == cow2) idx2 = j;
		}
		s1 += (idx1 < idx2);
		s2 += (idx2 < idx1);
	}
	return s1 == k || s2 == k;
}


vector<vector<bool>> visited;
int work(int c1, int c2){
	if(c1 > n || c2 > n || c1 == c2 || visited[min(c1, c2)][max(c1, c2)])
		return 0;
	visited[min(c1, c2)][max(c1, c2)] = 1;
	return check(c1, c2) + work(c1+1, c2) + work(c1, c2+1);
}


void solve(){
	cin >> k >> n;
	ranks.resize(k, vi(n));
	visited.assign(n+1, vector<bool>(n+1, false));
	For(i, k){
		For(j, n)
			cin >> ranks[i][j];
	}
	cout << work(1, 2) << endl;


}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
