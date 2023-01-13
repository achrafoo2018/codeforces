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


struct Point{
	ll x, y;
	void read(){
		cin >> x >> y;
	}
	Point operator -(const Point& b) const{
		return Point{x- b.x, y-b.y};
	}
	void operator -= (const Point& b){
		x -= b.x;
		y -= b.y;
	}
	ll operator *(const Point& b) const{
		return x * b.y - y *b.x;
	}
};


void solve(){
	vector<pair<int,int>> p1(3), p2(3);
	For(i, 3){
		int x, y;
		cin >> x >> y;
		p1[i].first = x;
		p1[i].second = y;
		p2[i].first = y;
		p2[i].second = x;
	}
	sort(all(p1));
	sort(all(p2));
	cout << 3 << endl;
	cout << p1[0].first << " " << p1[0].second << " " << p1[1].first << " " << p1[0].second << endl;
	cout << p1[1].first << " " << p2[0].first << " " << p1[1].first << " " << p2[2].first << endl;
	cout << p1[2].first << " " << p1[2].second << " " << p1[1].first << " " << p1[2].second << endl;

}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
