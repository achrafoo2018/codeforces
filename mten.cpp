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

void solve(){
	int n;
	scanf("%d", &n);
	vll arr(n);
	For(i, n){
		cin >> arr[i];
		if(arr[i] == 0)
			continue;
		if(arr[i] % 2)
			arr[i] += arr[i] % 10;
		while(arr[i] < 10)
			arr[i] += arr[i] % 10;
	}
	// debug() << imie(arr);
	if(arr[0] % 5 == 0){
		For(i, n){
			if(arr[i] % 5 != 0){
				no;
				return;
			}
		}
		int mx = *max_element(all(arr));
		int mn = *min_element(all(arr));
		if(mn == 0 && mx != mn || mx != mn && (mx - mn > 5)){
			no;
			return;
		}
		if(mx - mn == 5 && mx % 10 == 5){
			no;
			return;
		}
	}else if((arr[0] / 10) % 2 && arr[0]%10 != 6 || (arr[0] / 10) % 2 == 0 && arr[0]%10 == 6){
		For(i, n){
			if((arr[i] / 10) % 2 && arr[i] % 10 == 6){
				no;
				return;
			}
			if((arr[i] / 10) % 2 == 0 && arr[i] % 10 != 6){
				no;
				return;
			}
			if(arr[i] % 5 == 0){
				no;
				return;
			}
		}
	}else{
		For(i, n){
			if((arr[i] / 10) % 2 && arr[i] % 10 != 6){
				no;
				return;
			}
			if((arr[i] / 10) % 2 == 0 && arr[i] % 10 == 6){
				no;
				return;
			}
			if(arr[i] % 5 == 0){
				no;
				return;
			}
		}
	}
	yes;
}

int main(){
	// fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t = 1;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}
