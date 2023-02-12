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

int n;
vector<vector<pll>> cards;
map<ll, map<ll, ll>> dp[4][6];
ll work(int i, int j, int cost, int nb){
	debug() << imie(i) imie(j);
	if(i == n){
		return 0;
	}
	if(cost > 3) return -1e18;
	if(j == cards[i].size() || cost == 3){
		return dp[cost][j][i][nb] = work(i+1, 0, 0, nb);
	}
	if(dp[cost][j].count(i) && dp[cost][j][i].count(nb)){
		return dp[cost][j][i][nb];
	}
 	return dp[cost][j][i][nb] = max( ((nb > 0 && (nb+1) % 10 == 0) ? 2 : 1) * cards[i][j].second + work(i, j+1, cost+cards[i][j].first, nb+1),
					work(i, j+1, cost, nb));
}
void solve(){
	cin >> n;
	cards.resize(n);
	For(i, n){
		ll k; cin >> k;
		vector<ll> turn[3];
		For(j, k){
			ll c, d; cin >> c >> d;
			c--;
			turn[c].PB(d);
		}
		For(j, 3){
			sort(all(turn[j]), greater<ll>());
			if(j == 0){
				For(k, min(3, (int)turn[j].size())){
					cards[i].PB({j+1, turn[j][k]});
				}
			}else{
				if(turn[j].size())
					cards[i].PB({j+1, turn[j][0]});
			}
		}
	}
	cout << work(0, 0, 0, 0) << endl;

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
