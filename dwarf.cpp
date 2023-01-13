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

vll price;
map<ll, pll> crafts;
map<ll, ll> bestPrice;
ll work(ll item){
	if(bestPrice.find(item) != bestPrice.end()){
		return bestPrice[item];
	}
	bestPrice[item] = price[item-1];
	if(crafts.find(item) != crafts.end()){
		bestPrice[item] = min(bestPrice[item], work(crafts[item].first) + work(crafts[item].second));
	}
	return bestPrice[item];
}

void solve(){
	ll n, m; cin >> n >> m;
	price.resize(n);
	crafts.clear();
	bestPrice.clear();
	For(i, n){
		cin >> price[i];
	}	
	For(i, m){
		ll a, x, y; cin >> a >> x >> y;
		crafts[a] = {x, y};
		crafts[x] = {a, y};
	}
	ll ans = work(1LL);
	bestPrice.clear();
	
	cout << work(1LL) << endl;
	// debug() << imie(bestPrice);

}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("dwarf.in", "r", stdin);
	// freopen("dwarf.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
