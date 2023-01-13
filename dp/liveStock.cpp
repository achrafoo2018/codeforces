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

vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

vector<string> ans;
vector<string> res;
bitset<8> chosen;
int n;
vector<pair<string, string>> constraints;
bool check(){
	For(i, 8){
		For(j, n){
			if(constraints[j].second == res[i]){
				if(!(i > 0 && res[i-1] == constraints[j].first || i < 7 && res[i+1] == constraints[j].first)){
					return false;
				}
			}
		}
	}
	return true;
}

bool better(){
	For(i, 8){
		if(res[i] != ans[i])
			return res[i] < ans[i];
	}
	return false;
}

void work(){
	if(res.size() == 8){
		if(check()){
			if(ans.size() == 0){
				For(i, 8)
					ans.PB(res[i]);
			}
			else if(better()){
				For(i, 8){
					ans[i] = res[i];
				}
			}
		}else{
			return;	
		}
	}
	For(i, 8){
		if(chosen[i]) continue;
		chosen[i] = 1;
		res.push_back(cows[i]);
		work();
		chosen[i] = 0;
		res.pop_back();
	}
}


void solve(){
	cin >> n;
	For(i, n){
		string c1, c2;
		cin >> c1;
		For(j, 4){
			string s;
			cin >> s;
		}
		cin >> c2;
		constraints.PB({c1, c2});
	}
	work();
	for(string cow : ans){
		cout << cow << endl;
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
