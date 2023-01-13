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
const int N = 32007;
vi sieve(int n){
	bool arr[n];
	vi primes;
	arr[0] = arr[1] = true;
	for(int i=2; i*i < n; i++){
		if(!arr[i]){
			for(int j=i*i; j < n; j += i)
				arr[j] = true;
		}
	}
	For(i, n){
		if(!arr[i])
			primes.push_back(i);
	}
	return primes;
}
vi primes;

void solve(){
	debug() << imie(primes.size());
	int n; cin >> n;
	vll arr(n);
	For(i, n){
		cin >> arr[i];
	}
	int i = 0;
	set<ll> factors;
	while(i < n){
		for(int j=0; j < primes.size(); j++){
			if(arr[i] % primes[j] == 0){
				if(factors.find(primes[j]) != factors.end()){
					yes; return;
				}
				factors.insert(primes[j]);
				while(arr[i] % primes[j] == 0)
					arr[i] /= primes[j];
			}
		}
		if(arr[i] != 1){
			if(factors.find(arr[i]) != factors.end()){
				yes; return;
			}
			factors.insert(arr[i]);
		}
		i++;
	}
	no;
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	cin >> t;
	primes = sieve(N);
	while(t--)
		solve();
	return 0;
}
