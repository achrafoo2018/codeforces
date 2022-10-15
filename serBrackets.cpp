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

struct segment_tree{
	int size;
	vpii tree;
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size, make_pair(0, 0));
    }

    void build(vector<char> &arr){
        init(arr.size());
        build(arr, 0, 0, size);
    }

    void build(vector<char> &arr, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < arr.size()){
                tree[x].first = arr[lx] == '(';
                tree[x].second = arr[lx] == ')';
            }
            return;
        }
        int m = (lx+rx) / 2;
        build(arr, 2*x+1, lx, m);
        build(arr, 2*x+2, m, rx);
        pii left = tree[2*x+1];
        pii right = tree[2*x+2];
        tree[x] = merge(left, right);
    }

    void update(int i){
        update(i, 0, 0, size);
    }

    void update(int i, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x].first = !tree[x].first;
            tree[x].second = !tree[x].second;
            return;
        }
        int m = (lx+rx) / 2;
        if(i < m){
            update(i, 2*x+1, lx, m);
        }else{
            update(i, 2*x+2, m, rx);
        }
        pii left = tree[2*x+1];
        pii right = tree[2*x+2];
        tree[x] = merge(left, right);
    }

    pii merge(pii left, pii right){
        pii ans = make_pair(right.first, left.second);
        int diff = left.first - right.second;
        if(diff > 0)
            ans.first += diff;
        else
            ans.second -= diff;
        return ans;
    }
};


void solve(){
    int n; cin >> n;
    vector<char> arr(n);
    for(char &c : arr)
        cin >> c;
    segment_tree st;
    st.build(arr);
    int m; cin >> m;
    while(m--){
        int q; cin >> q;
        if(q == 0){
            pii ans = st.tree[0];
            if(ans.first == 0 && ans.second == 0){
                yes;
            }else{
                no;
            }
        }else{
            st.update(--q);
        }
    }
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t = 10;
	// cin >> t;
	For(i, t){
        cout << "Test " << (i+1) << ":" << endl;
        solve();
    }
	return 0;
}
