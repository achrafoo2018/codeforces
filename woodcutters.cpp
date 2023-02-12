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

int n;
vpll arr;
int dp[100007];
int bs(int v){
	int l = 0, r = n-1;
	int ans = n;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(arr[mid].first <= v){
			l = mid+1;
		}else{
			ans = mid;
			r = mid-1;
		}
	}
	return ans;
}

int work(int i, int state){
	if(i == n) return 0;
	int &ans = dp[i];
	if(ans != -1) return ans;
	int r = bs(arr[i].first+arr[i].second);	
	if(state){
		if(i < n-1)
			ans = 1 + work(i+1, (arr[i+1].first-arr[i].first > arr[i+1].second));
		// else
		// 	ans = 1 + work(i+1, 0);
	}else{
		if(r < n){
			ans = 1 + work(r, (arr[r].first-(arr[i].first+arr[i].second) > arr[i].second));
		}else{
			ans = 1 + work(r, 0);
		}
	}
	return ans = max(ans, work(i+1, (i < n-1 && (arr[i+1].first-arr[i].first > arr[i+1].second))));
}
void solve(){
	memset(dp, -1, sizeof(dp));
	cin >> n;
	arr.resize(n);
	For(i, n) 
		cin >> arr[i].first >> arr[i].second;
	sort(all(arr));
	cout << work(0, 1) << endl;
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
