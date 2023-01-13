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
    segment_tree *left, *right;
    int from, to, value;
    segment_tree(int from, int to)
        : from(from), to(to), left(NULL), right(NULL), value(INT_MAX) {}
};


segment_tree *build(const vector<int> &arr, int l, int r){
    if (l > r)
        return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r){
        res->value = arr[l];
    }
    else{
        int m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        if (res->left != NULL)
            res->value = min(res->value, res->left->value);
        if (res->right != NULL)
            res->value = min(res->value, res->right->value);
    }
    return res;
}


int update(segment_tree *tree, int i, int val){
    if (tree == NULL)
        return INT_MAX;
    if (tree->to < i)
        return tree->value;
    if (i < tree->from)
        return tree->value;
    if (tree->from == tree->to && tree->from == i){
        tree->value = val;
    }
    else{
        tree->value = min(update(tree->left, i, val), update(tree->right, i, val));
    }
    return tree->value;
}


int query(segment_tree *tree, int l, int r) {
    if (tree == NULL) return INT_MAX;
    if (l <= tree->from && tree->to <= r) 
        return tree->value;
    if (tree->to < l) 
        return INT_MAX;
    if (r < tree->from) 
        return INT_MAX;
    return min(query(tree->left, l, r), query(tree->right, l, r));
}

void solve(){
	int n, q; cin >> n >> q;
    vi arr(n);
    For(i, n)
        cin >> arr[i];
    segment_tree *seg_tree = build(arr, 0, n-1);
    For(i, q){
        int p, a, b; cin >> p >> a >> b;
        if(p == 2){
            cout << query(seg_tree, --a, --b) << endl;
        }else{
            update(seg_tree, --a, b);
        }
    }
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
