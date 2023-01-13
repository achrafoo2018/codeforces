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


float roundd(float var){
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);
	vector<string> presidents(n);
	For(i, n){
		cin >> presidents[i];
		arr[i].second = i;
	}
	debug() << imie(arr);
	int inv = 0;
	For(i, m){
		string s;
		cin >> s;
		int nb_X = count(all(s), 'X');
		if(nb_X > 1 || nb_X == 0){
			inv++;
			continue;
		}
		int pos = -1;
		For(j, n){
			if(s[j] == 'X'){
				pos = j;
				break;
			}
		}
		arr[pos].first++;
	}
	sort(all(arr), [&](pii &a, pii &b){
		if(a.first > b.first){
			return true;
		}else if(a.first < b.first){
			return false;
		}else{
			return a.second < b.second;
		}
	});
	debug() << imie(arr);
	cout << setprecision(2);
	cout << fixed;

	For(i, n){
		cout << presidents[arr[i].second] << " " << roundd((arr[i].first * 100 ) / (float)m) << "%" << endl;
	}
	cout << "Invalid " << roundd((inv * 100 ) / (float)m) << "%" << endl;
}

int main(){
	fastio;
	freopen("bad.in", "r", stdin);
	freopen("bad.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
